
(* ------------------- *)
(*      aleatoire      *)
(* ------------------- *)

let rand_init() : unit = Random.self_init() ;;
let rand_init_expl(n : int) : unit = Random.init(n) ;;
let rand_int_0(n : int) : int = Random.int(n+1) ;;
let rand_int(n, p : int * int) : int = 
  if n <= p then Random.int(p - n + 1) + n
  else Random.int(n - p + 1) + p ;;


(* ------------------------ *)
(*        listes            *)
(* ------------------------ *)



let len(l : 'a list) : int = List.length l ;;
let empty() : 'a list = 
  []
;;
let isempty(l : 'a list) : bool =
  l = []
;;
let fst(l : 'a list) : 'a =
  match l with
    [] -> failwith("error fst : list is empty")
  | hd::_ -> hd
;;
let rec lst(l : 'a list) : 'a =
  match l with
    [] -> failwith("error lst : list is empty")
    | hd::[] -> hd
    | _::tail -> lst(tail)
;;
let nth(l, k : 'a list * int) : 'a = 
  let rec nth1(l, k) =
    match l with
      []->  failwith("error nth : index out of bounds")
    | hd::tail -> if k = 0 then hd else nth1(tail,k-1)
  in
    if k < 0
    then failwith("error  nth : index must be positive")
    else nth1(l, k)
;;
let add_fst(l, e : 'a list * 'a) : 'a list = e::l ;;
let rec add_lst(l, e : 'a list * 'a) : 'a list =
  match l with
    [] -> [e]
  | hd::tail -> hd::add_lst(tail, e)
;;
let add_nth(l, e, k  : 'a list * 'a * int) : 'a list =
  let rec add_nth1(l, e, k) =
    match l with
      [] -> [e]
    | hd ::tail -> if k = 0 then e::l else hd::add_nth1(tail, e, k-1)
  in 
    if k < 0
    then failwith("error add_nth : index must be positive")
    else
      if k > len(l)
      then failwith("error add_nth : index out of bounds")
      else add_nth1(l, e, k)
;;
let rem_fst(l : 'a list) : 'a list = 
  match l with
    [] -> failwith("error rem_fst : list is empty")
    | _::tail -> tail
;;
let rec rem_lst(l : 'a list) : 'a list =
  match l with
    [] -> failwith("error rem_lst : list is empty")
    | [x] -> []
    | x::tail -> x::rem_lst(tail)
 ;;
let rem_nth(l, k : 'a list * int) : 'a list =
  let rec rem_nth1(l, k) =
    match l with
    | [] -> failwith("error rem_nth : index out of bounds")
    | hd::tail -> if k = 0 then tail else hd::rem_nth1(tail, k-1)
  in
    if k < 0 
    then failwith("error rem_nth : index must be positive")
    else rem_nth1(l, k)
;;
let rec concat(l1, l2 : 'a list * 'a list) : 'a list = 
  match l1 with
    [] -> l2
  | hd::tail -> hd::concat(tail, l2)
;;


(* ------------------------ *)
(*        tableaux          *)
(* ------------------------ *)

let arr_len(t : 'a array) : int = Array.length t ;;
let arr_make(n, v : int * 'a) : 'a array = 
  if n < 0
  then failwith("erreur arr_make ; parametre invalide")
  else Array.make n v 
;;
type 'a matrix = 'a array array ;;
let mat_make(n, m, v : int * int * 'a) : 'a matrix = 
  if n < 0 || m < 0
  then failwith("erreur mat_make ; parametre invalide")
  else Array.make_matrix n m v 
;;

(* ------------------------ *)
(*        ensembles         *)
(* ------------------------ *)


type 'a t_set = 'a list ;;
let s_empty() : 'a t_set = 
  empty()
;;
let s_isempty (s : 'a t_set) : bool =
  isempty(s)
;;
let rec s_add(s, v : 'a t_set * 'a) : 'a t_set =
  if isempty(s)
  then add_fst(s, v)
  else
    let (f, r) = (fst(s), rem_fst(s)) in
      if f = v
      then s
      else 
        let newr = s_add(r, v) in
          add_nth(newr, f, rand_int(0, len(newr)))
;;
let rec s_in(s, v : 'a t_set * 'a) : bool =
  if isempty(s)
  then false
  else
    let (f, r) = (fst(s), rem_fst(s)) in
      if f = v
      then true
      else s_in(r, v)
;;
let s_choice (s : 'a t_set) : 'a =
  let n : int = len(s) in
    if n = 0
    then failwith("erreur s_choice : empty set")
    else nth(s, rand_int(0, n-1))
;;
let rec s_rem(s, v : 'a t_set * 'a) : 'a t_set =
  if isempty(s)
  then s
  else
    let (f, r) = (fst(s), rem_fst(s)) in
      if f = v
      then r
      else 
        let newr = s_rem(r, v) in
          add_nth(newr, f, rand_int(0, len(newr))) 
;;
let rec s_union(e, f : 'a t_set * 'a t_set) : 'a t_set =
  if s_isempty(e)
  then f
  else
    let x : 'a = s_choice(e) in
    let new_e : 'a t_set = s_rem(e, x) in
      s_union(new_e, s_add(f, x))
;;
let s_card(s : 'a t_set) : int = len(s) ;;


(* ------------------------ *)
(*    multi-ensembles V1    *)
(* ------------------------ *)


type 'a t_mset = ('a * int) list ;;
let ms_empty() : 'a t_mset = 
  empty() 
;;
let ms_isempty(ms : 'a t_mset) : bool =
  isempty(ms)
;;
let rec ms_add(ms, v : 'a t_mset * 'a) : 'a t_mset =
  if isempty(ms)
  then add_fst(ms, (v, 1))
  else
    let ((x, nb), r) = (fst(ms), rem_fst(ms)) in
      if x = v
      then add_nth(r, (x, nb + 1), rand_int(0, len(r)))
      else
        let newr = ms_add(r, v) in
          add_nth(newr, (x, nb), rand_int(0, len(newr)))
;;
let ms_choice (ms : 'a t_mset) : 'a =
  let n : int = len(ms) in
    if n = 0
    then failwith("erreur ms_choice : empty set")
    else 
      let (v, nb) : 'a * int = nth(ms, rand_int(0, n-1)) in
        v
;;
let rec ms_rem(ms, v : 'a t_mset * 'a) : 'a t_mset =
  if isempty(ms)
  then ms
  else    
    let ((x, nb), r) = (fst(ms), rem_fst(ms)) in
      if x = v
      then 
        if nb = 1
        then r
        else add_nth(r, (x, nb - 1), rand_int(0, len(r)))
      else
        let newr = ms_rem(r, v) in
          add_nth(newr, (x, nb), rand_int(0, len(newr)))
;;
let rec ms_in(ms, v : 'a t_mset * 'a) : bool =
  if isempty(ms)
  then false
  else    
    let ((x, nb), r) = (fst(ms), rem_fst(ms)) in
      if x = v
      then true
      else ms_in(r, v) 
;;
let rec ms_occnb(ms, v : 'a t_mset * 'a) : int =
  if isempty(ms)
  then 0
  else    
    let ((x, nb), r) = (fst(ms), rem_fst(ms)) in
      if x = v
      then nb
      else ms_occnb(r, v) 
;;
let rec ms_card(ms : 'a t_mset) : int =
  if isempty(ms)
  then 0
  else    
    let ((x, nb), r) = (fst(ms), rem_fst(ms)) in
      nb + ms_card(r) 
;;
let rec ms_union(e, f : 'a t_mset * 'a t_mset) : 'a t_mset =
  if ms_isempty(e)
  then f
  else
    let x : 'a = ms_choice(e) in
    let new_e : 'a t_mset = ms_rem(e, x) in
      ms_union(new_e, ms_add(f, x))
;;


(* ------------------------ *)
(*    multi-ensembles V2    *)
(* ------------------------ *)


type 'a t_mset = 'a list ;;
let ms_empty() : 'a t_mset = 
  empty()
;;
let rec ms_add(ms, v : 'a t_mset * 'a) : 'a t_mset =
    add_nth(ms, v, rand_int(0, len(ms))) 
;;
let ms_isempty (ms : 'a t_mset) : bool =
  isempty(ms)
;;
let ms_choice (ms : 'a t_mset) : 'a =
  let n : int = len(ms) in
    if n = 0
    then failwith("erreur ms_choice : empty set")
    else nth(ms, rand_int(0, n-1))
;;
let rec ms_rem(ms, v : 'a t_mset * 'a) : 'a t_mset =
  if ms_isempty(ms)
  then ms
  else
    let (f, r) = (fst(ms), rem_fst(ms)) in
      if f = v
      then r
      else add_fst(ms_rem(r, v), f)
;;
let rec ms_in(ms, v : 'a t_mset * 'a) : bool =
  if ms_isempty(ms)
  then false
  else
    let (f, r) = (fst(ms), rem_fst(ms)) in
      if f = v
      then true
      else ms_in(r, v)
;;
let rec ms_occnb(ms, v : 'a t_mset * 'a) : int =
  if ms_isempty(ms)
  then 0
  else
    let (f, r) = (fst(ms), rem_fst(ms)) in
    let nb : int = ms_occnb(r, v) in
      if f = v
      then nb + 1
      else nb
;;
let rec ms_card(ms : 'a t_mset) : int =
  len(ms)
;;
let rec ms_union(e, f : 'a t_mset * 'a t_mset) : 'a t_mset =
  concat(e, f)
;;


(* --------------------------- *)
(* ensembles avec identifiants *)
(* --------------------------- *)


type ('a, 'b) t_idset = ('a * 'b) t_set ;;
let ids_empty() : ('a, 'b) t_idset = s_empty() ;;
let ids_isempty(s : ('a, 'b) t_idset) : bool = s_isempty(s) ;;
let ids_choice(s : ('a, 'b) t_idset) : 'a =
  if ids_isempty(s)
  then failwith("erreur ids_choice : ensemble vide")
  else
    let (id, v) : 'a * 'b = s_choice(s) in 
      id
;;
let rec ids_idset(s : ('a, 'b) t_idset) : 'a t_set =
  if ids_isempty(s)
  then s_empty()
  else
    let (ids, vs) : 'a * 'b = s_choice(s) in
    let rs : ('a, 'b) t_idset = s_rem(s, (ids, vs)) in
      s_add(ids_idset(rs), ids)
;;
let ids_in(s, id : ('a, 'b) t_idset * 'a) : bool =
  s_in(ids_idset(s), id)
;;
let rec ids_val(s, id : ('a, 'b) t_idset * 'a) : 'b =
  if ids_isempty(s)
  then failwith("erreur ids_val : identifiant inconnu")
  else
    let (ids, vs) : 'a * 'b = s_choice(s) in
      if ids = id
      then vs
      else ids_val(s_rem(s, (ids, vs)), id)
;;
let ids_add(s, (id, v) : ('a, 'b) t_idset * ('a * 'b)) : ('a, 'b) t_idset =
  if ids_in(s, id)
  then failwith("erreur ids_add : identifiant deja present")
  else s_add(s, (id, v))
;;
let ids_card(s : ('a, 'b) t_idset) : int =
  s_card(s)
;;
let ids_rem(s, id : ('a, 'b) t_idset * 'a) : ('a, 'b) t_idset =
  if not(ids_in(s, id)) 
  then failwith("erreur ids_rem : identifiant inconnu")
  else s_rem(s, (id, ids_val(s, id)))
;;



(* ------------------------ *)
(*         files            *)
(* ------------------------ *)

type 'a t_queue = 'a list ;;

let emptyq() : 'a t_queue = empty() ;;
let isemptyq(q : 'a t_queue) : bool = isempty(q) ;;
let fstq(q : 'a t_queue) : 'a = fst(q) ;;
let add_lstq(q, x : 'a t_queue * 'a) : 'a t_queue = add_lst(q, x) ;;
let rem_fstq(q : 'a t_queue) : 'a t_queue = rem_fst(q) ;;
let lenq(q : 'a t_queue) : int = len(q) ;;


type 'a t_mutqueue = ('a t_queue) ref ;;

let m_emptyq() : 'a t_mutqueue = 
  ref (emptyq())
;;
let m_isemptyq(q : 'a t_mutqueue) : bool = 
  isemptyq(!q) 
;;

let m_enqueue(q, x : 'a t_mutqueue * 'a) : unit = 
  q := add_lstq(!q, x) 
;;
let m_dequeue(q : 'a t_mutqueue) : 'a = 
  if isemptyq(!q)
  then failwith("erreur m_dequeue : file vide")
  else
    let x : 'a = fstq(!q) in 
      (
      q := rem_fstq(!q) ;  
      x
      ) 
;;
let m_topq(q : 'a t_mutqueue) : 'a =
  if isemptyq(!q)
  then failwith("erreur m_topq : file vide")
  else fstq(!q)
;;


(* ------------------------ *)
(*         piles            *)
(* ------------------------ *)

type 'a t_stack = 'a list ;;

let emptys() : 'a t_stack = empty() ;;
let isemptys(p : 'a t_stack) : bool = isempty(p) ;;
let fsts(p : 'a t_stack) : 'a = fst(p) ;;
let add_fsts(p, x : 'a t_stack * 'a) : 'a t_stack = add_fst(p, x) ;;
let rem_fsts(p : 'a t_stack) : 'a t_stack = rem_fst(p) ;;
let lens(p : 'a t_stack) : int = len(p) ;;


type 'a t_mutstack = ('a t_stack) ref ;;

let m_emptys() : 'a t_mutstack = 
  ref (emptys()) 
;;
let m_isemptys(s : 'a t_mutstack) : bool = 
  isemptys(!s) 
;;
let m_push(s, x : 'a t_mutstack * 'a) : unit = 
  s := add_fsts(!s, x) 
;;
let m_pop(s : 'a t_mutstack) : 'a = 
  if isemptys(!s)
  then failwith("erreur m_pop : pile vide")
  else
    let x : 'a = fsts(!s) in 
    (
    s := rem_fsts(!s) ;  
    x
    ) 
;;
let m_tops(s : 'a t_mutstack) : 'a = 
  if isemptys(!s)
  then failwith("erreur m_tops : pile vide")
  else fsts(!s)
;;


(* ------------------------ *)
(*   arbres binaires        *)
(* ------------------------ *)


type 'a t_btree = B_NIL | B_RT of 'a * 'a t_btree * 'a t_btree ;;

let bt_empty() : 'a t_btree = B_NIL ;;
let bt_rooting(x, g, d : 'a * 'a t_btree * 'a t_btree) : 'a t_btree = 
  B_RT(x, g, d) 
;;
let bt_isempty(a : 'a t_btree) : bool = (a = B_NIL) ;;
let bt_root(a : 'a t_btree) : 'a = 
  match a with
    B_NIL -> failwith("erreur bt_root : arbre vide")
  | B_RT(x, _, _) -> x
;;
let bt_subleft(a : 'a t_btree) : 'a t_btree = 
  match a with
    B_NIL -> failwith("erreur bt_subleft : arbre vide")
  | B_RT(_, g, _) -> g
;;
let bt_subright(a : 'a t_btree) : 'a t_btree = 
  match a with
    B_NIL -> failwith("erreur bt_subright : arbre vide")
  | B_RT(_, _, d) -> d
;;

let rec bt_nbnodes(t : 'a t_btree) : int =
  if bt_isempty(t)
  then 0
  else 1 + bt_nbnodes(bt_subleft(t)) + bt_nbnodes(bt_subright(t))
;;
let rec bt_height(t : 'a t_btree) : int =
  if bt_isempty(t)
  then 0
  else 
    let h1 : int = bt_height(bt_subleft(t))
          and h2 : int = bt_height(bt_subright(t)) in
      if h1 > h2 then 1 + h1 else 1 + h2
;;
let bt_isleaf(t : 'a t_btree) : bool =
  if bt_isempty(t)
  then failwith("erreur bt_isleaf : l'arbre est vide")
  else bt_isempty(bt_subleft(t)) && bt_isempty(bt_subright(t))
;;
let bt_isinnode(t : 'a t_btree) : bool =
  if bt_isempty(t)
  then failwith("erreur bt_isinnode : l'arbre est vide")
  else not(bt_isleaf(t))
;;
let rec bt_nbleaves(t : 'a t_btree) : int = 
  if bt_isempty(t)
  then 0
  else 
    if bt_isleaf(t)
    then 1
    else bt_nbleaves(bt_subleft(t)) + bt_nbleaves(bt_subright(t))
;;
let rec bt_nbinnodes(t : 'a t_btree) : int = 
  if bt_isempty(t)
  then 0
  else 
    if bt_isleaf(t)
    then 0
    else 
      1 + bt_nbinnodes(bt_subleft(t)) + bt_nbinnodes(bt_subright(t))
;;



(* ------------------------ *)
(*   arbres ternaires       *)
(* ------------------------ *)


type 'a t_ttree = T_NIL | T_RT of 'a * 'a t_ttree * 'a t_ttree * 'a t_ttree ;;

let tt_empty() : 'a t_ttree = T_NIL ;;
let tt_rooting(x, g, m, d : 'a * 'a t_ttree * 'a t_ttree * 'a t_ttree) : 'a t_ttree = 
  T_RT(x, g, m, d) 
;;
let tt_isempty(a : 'a t_ttree) : bool = (a = T_NIL) ;;
let tt_root(a : 'a t_ttree) : 'a = 
  match a with
    T_NIL -> failwith("erreur tt_root : arbre vide")
  | T_RT(x, _, _, _) -> x
;;
let tt_subleft(a : 'a t_ttree) : 'a t_ttree = 
  match a with
    T_NIL -> failwith("erreur tt_subleft : arbre vide")
  | T_RT(_, g, _, _) -> g
;;
let tt_submid(a : 'a t_ttree) : 'a t_ttree = 
  match a with
    T_NIL -> failwith("erreur tt_submid : arbre vide")
  | T_RT(_, _, m, _) -> m
;;
let tt_subright(a : 'a t_ttree) : 'a t_ttree = 
  match a with
    T_NIL -> failwith("erreur tt_subright : arbre vide")
  | T_RT(_, _, _, d) -> d
;;


(* ------------------------ *)
(*    arbres et forets      *)
(* ------------------------ *)


type ('a,'b) t_gtree = G_RT of 'a * ('a,'b) t_forest
  and ('a,'b) t_forest = ('b * ('a,'b) t_gtree) t_mset
;;
let gt_rooting(value, subs : 'a * ('a, 'b) t_forest) : ('a,'b) t_gtree =
  G_RT(value, subs)
;;
let gt_root(gt : ('a, 'b) t_gtree) : 'a =
  match gt with
   | G_RT(value, _) -> value
;;
let gt_subs(gt : ('a, 'b) t_gtree) : ('a, 'b) t_forest =
  match gt with
    | G_RT(_, subs) -> subs
;;
let gt_isleaf(gt : ('a, 'b) t_gtree ) : bool =
  match gt with
   | G_RT(_, subs) -> ms_isempty(subs)
;;
let gt_isinnode(gt : ('a, 'b) t_gtree ) : bool =
  match gt with
   | G_RT(_, subs) -> not(ms_isempty(subs))
;;



(* ------------------------ *)
(*    graphes orientes      *)
(* ------------------------ *)



type ('a, 'b, 'c, 'd) t_dirgraph = ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset ;;

let dg_empty() : ('a, 'b, 'c, 'd) t_dirgraph =
  (ids_empty(), ids_empty())
;;

let dg_isempty(g : ('a, 'b, 'c, 'd) t_dirgraph) : bool =
  let (vs, va) : ('a, 'b) t_idset * ('c, 'a * 'a *'d) t_idset = g in
    ids_isempty(vs)
;;

let dg_add_vtx(g, (idv, v) : ('a, 'b, 'c, 'd) t_dirgraph * ('a * 'b)) : ('a, 'b, 'c, 'd) t_dirgraph =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if ids_in(vtxs, idv)
    then failwith("erreur dg_add_vtx : sommet present")
    else (ids_add(vtxs, (idv, v)), arcs)
;;

let dg_add_arc(g, src, dst, (ida, va) : ('a, 'b, 'c, 'd) t_dirgraph * 'a * 'a * ('c * 'd)) : ('a, 'b, 'c, 'd) t_dirgraph =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if ids_in(arcs, ida)
    then failwith("erreur dg_add_arc : arc present")
    else 
      if not(ids_in(vtxs, src) && ids_in(vtxs, dst))
      then failwith("erreur dg_add_arc : un sommet absent")
      else (vtxs, ids_add(arcs, (ida, (src, dst, va))))
;;

let dg_vtx_ids(g : ('a, 'b, 'c, 'd) t_dirgraph) : 'a t_set =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    ids_idset(vtxs)
;;

let dg_arc_ids(g : ('a, 'b, 'c, 'd) t_dirgraph) : 'c t_set =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    ids_idset(arcs)
;;

let dg_vtx_in(g, idv : ('a, 'b, 'c, 'd) t_dirgraph * 'a) : bool =
  s_in(dg_vtx_ids(g), idv)
;;

let dg_arc_in(g, ida : ('a, 'b, 'c, 'd) t_dirgraph * 'c) : bool =
  s_in(dg_arc_ids(g), ida)
;;

let dg_arc_src(g, ida : ('a, 'b, 'c, 'd) t_dirgraph * 'c) : 'a =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(arcs, ida))
    then failwith("erreur dg_arc_src : arc absent")
    else 
      let (src, dst, va) : 'a * 'a *'d = ids_val(arcs, ida) in
        src
;;

let dg_arc_dst(g, ida : ('a, 'b, 'c, 'd) t_dirgraph * 'c) : 'a =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(arcs, ida))
    then failwith("erreur dg_arc_dst : arc absent")
    else 
      let (src, dst, va) : 'a * 'a *'d = ids_val(arcs, ida) in
        dst
;;

let rec dg_inarcs_aux(arcs, idv : ('c, 'a * 'a *'d) t_idset * 'a) : 'c t_set =
    if ids_isempty(arcs)
    then s_empty()
    else
      let (ida, (src, dst, va)) : 'c * ('a * 'a *'d) = s_choice(arcs) in
      let rarcs : ('c, 'a * 'a *'d) t_idset = ids_rem(arcs, ida) in
      let rinarcs : 'c t_set = dg_inarcs_aux(rarcs, idv) in
        if dst = idv
        then s_add(rinarcs, ida)
        else rinarcs
;;

let rec dg_inarcs(g, idv : ('a, 'b, 'c, 'd) t_dirgraph * 'a) : 'c t_set =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(vtxs, idv))
    then failwith("erreur dg_inarcs : sommet inconnu")
    else dg_inarcs_aux(arcs, idv)
;;

let rec dg_outarcs_aux(arcs, idv : ('c, 'a * 'a *'d) t_idset * 'a) : 'c t_set =
    if ids_isempty(arcs)
    then s_empty()
    else
      let (ida, (src, dst, va)) : 'c * ('a * 'a *'d) = s_choice(arcs) 
      in
      let rarcs : ('c, 'a * 'a *'d) t_idset = ids_rem(arcs, ida) in
      let routarcs : 'c t_set = dg_outarcs_aux(rarcs, idv) in
        if src = idv
        then s_add(routarcs, ida)
        else routarcs
;;

let rec dg_outarcs(g, idv : ('a, 'b, 'c, 'd) t_dirgraph * 'a) : 'c t_set =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(vtxs, idv))
    then failwith("erreur dg_outarcs : sommet inconnu")
    else dg_outarcs_aux(arcs, idv)
;;

let dg_vtx_val(g, idv : ('a, 'b, 'c, 'd) t_dirgraph * 'a) : 'b =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(vtxs, idv))
    then failwith("erreur dg_vtx_val : sommet inconnu")
    else ids_val(vtxs, idv)
;;

let dg_arc_val(g, ida : ('a, 'b, 'c, 'd) t_dirgraph * 'c) : 'd =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(arcs, ida))
    then failwith("erreur dg_arc_val : arc inconnu")
    else 
      let (s1, s2, va) : 'a * 'a * 'd = ids_val(arcs, ida) in
        va
;;

let dg_rem_vtx(g, idv : ('a, 'b, 'c, 'd) t_dirgraph * 'a) : ('a, 'b, 'c, 'd) t_dirgraph =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(vtxs, idv))
    then failwith("erreur dg_rem_vtx : sommet inconnu")
    else 
      if s_isempty(dg_inarcs(g, idv)) && s_isempty(dg_outarcs(g, idv))
      then (ids_rem(vtxs, idv), arcs)
      else failwith("erreur dg_rem_vtx : sommet non isole")
;;

let dg_rem_arc(g, ida : ('a, 'b, 'c, 'd) t_dirgraph * 'c) : ('a, 'b, 'c, 'd) t_dirgraph =
  let (vtxs, arcs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(arcs, ida))
    then failwith("erreur dg_rem_arc : arc inconnu")
    else (vtxs, ids_rem(arcs, ida))
;;


(* ------------------------ *)
(*    graphes non orientes  *)
(* ------------------------ *)


type ('a, 'b, 'c, 'd) t_graph = ('a, 'b) t_idset * ('c, 'a * 'a *'d) t_idset ;;

let g_empty() : ('a, 'b, 'c, 'd) t_graph =
  (ids_empty(), ids_empty())
;;

let g_isempty(g : ('a, 'b, 'c, 'd) t_graph) : bool =
  let (vs, ve) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    ids_isempty(vs)
;;

let g_add_vtx(g, (idv, v) : ('a, 'b, 'c, 'd) t_graph * ('a * 'b)) : ('a, 'b, 'c, 'd) t_graph =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if ids_in(vtxs, idv)
    then failwith("erreur g_add_vtx : sommet present")
    else (ids_add(vtxs, (idv, v)), edgs)
;;

let g_add_edg(g, ext1, ext2, (ide, ve) : ('a, 'b, 'c, 'd) t_graph * 'a * 'a * ('c * 'd)) : ('a, 'b, 'c, 'd) t_graph =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g 
  in
    if ids_in(edgs, ide)
    then failwith("erreur g_add_edg : arete presente")
    else 
      if not(ids_in(vtxs, ext1) && ids_in(vtxs, ext2))
      then failwith("erreur g_add_edg : un sommet absent")
      else (vtxs, ids_add(edgs, (ide, (ext1, ext2, ve))))
;;

let g_vtx_ids(g : ('a, 'b, 'c, 'd) t_graph) : 'a t_set =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    ids_idset(vtxs)
;;

let g_edg_ids(g : ('a, 'b, 'c, 'd) t_graph) : 'c t_set =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a *'d) t_idset = g in
    ids_idset(edgs)
;;

let g_vtx_in(g, idv : ('a, 'b, 'c, 'd) t_graph * 'a) : bool =
  s_in(g_vtx_ids(g), idv)
;;

let g_edg_in(g, ide : ('a, 'b, 'c, 'd) t_graph * 'c) : bool =
  s_in(g_edg_ids(g), ide)
;;

let g_vtx_of_edg(g, ide : ('a, 'b, 'c, 'd) t_graph * 'c) : 'a * 'a =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g 
  in
    if not(ids_in(edgs, ide))
    then failwith("erreur g_vtx_of_edg : arete absente")
    else 
      let (ext1, ext2, ve) : 'a * 'a *'d = ids_val(edgs, ide) in
        (ext1, ext2)
;;

let rec g_edg_of_vtx_aux(edgs, idv : ('c, 'a * 'a * 'd) t_idset * 'a) : 'c t_set =
  if ids_isempty(edgs)
  then s_empty()
  else
    let (ide, (ext1, ext2, ve)) : 'c * ('a * 'a * 'd) = s_choice(edgs) in
    let redgs : ('c, 'a * 'a *'d) t_idset = ids_rem(edgs, ide) in
    let rextedgs : 'c t_set = g_edg_of_vtx_aux(redgs, idv) in
      if (ext1 = idv) || (ext2 = idv)
      then s_add(rextedgs, ide)
      else rextedgs
;;

let rec g_edg_of_vtx(g, idv : ('a, 'b, 'c, 'd) t_graph * 'a) : 'c t_set =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(vtxs, idv))
    then failwith("erreur g_edg_of_vtx : sommet inconnu")
    else g_edg_of_vtx_aux(edgs, idv)
;;

let g_vtx_val(g, idv : ('a, 'b, 'c, 'd) t_graph * 'a) : 'b =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(vtxs, idv))
    then failwith("erreur g_vtx_val : sommet inconnu")
    else ids_val(vtxs, idv)
;;

let g_edg_val(g, ide : ('a, 'b, 'c, 'd) t_graph * 'c) : 'd =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(edgs, ide))
    then failwith("erreur g_edg_val : arete inconnue")
    else 
      let (s1, s2, ve) : 'a * 'a * 'd = ids_val(edgs, ide) in
        ve
;;

let g_rem_vtx(g, idv : ('a, 'b, 'c, 'd) t_graph * 'a) : ('a, 'b, 'c, 'd) t_graph =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(vtxs, idv))
    then failwith("erreur g_rem_vtx : sommet inconnu")
    else 
      if s_isempty(g_edg_of_vtx(g, idv))
      then (ids_rem(vtxs, idv), edgs)
      else failwith("erreur dg_rem_vtx : sommet non isole")
;;

let g_rem_edg(g, ide : ('a, 'b, 'c, 'd) t_graph * 'c) : ('a, 'b, 'c, 'd) t_graph =
  let (vtxs, edgs) : ('a, 'b) t_idset * ('c, 'a * 'a * 'd) t_idset = g in
    if not(ids_in(edgs, ide))
    then failwith("erreur g_rem_edg : arete inconnue")
    else (vtxs, ids_rem(edgs, ide))
;;




(* ----------------------------- *)
(* gestion memoires et pointeurs *)
(* ----------------------------- *)

(* ----------------------------- *)
(* gestion memoires et pointeurs *)
(* gestion adresses libres       *)
(* par list ocaml                *)
(* ----------------------------- *)

(* definition et initialisation memoire *)

let init_free(n : int) : (int list) ref = 
  let f : (int list) ref = ref (empty()) and indmax : int = n - 1 in
    (
    for i = indmax downto 0
    do f := add_fst(!f, i)
    done ;
    f
    )
;;

type 'a t_memory = {mem : 'a array ; len : int ; freel : (int list) ref} ;;


let make_memory(n, v : int * 'a) : 'a t_memory =
  {mem = arr_make(n, v); len = n ; freel = init_free(n)}
;;

(* fonctions de gestion des pointeurs *)


type 'a t_address = int ;;
type 'a t_pointer = ('a t_address) ref ;; 

let null : 'a t_address = -1 ;;


let malloc(mem, v : 'a t_memory * 'a) : 'a t_address = 
  if isempty(!(mem.freel))
  then failwith("erreur malloc : memoire saturee") 
  else 
    let ad : 'a t_address = fst(!(mem.freel)) in
      (
      mem.freel := rem_fst(!(mem.freel));
      mem.mem.(ad) <- v ;
      ad
      )
;;

let mfree(mem, ad : 'a t_memory * 'a t_address) : unit =
  let isfree(mem, ad : 'a t_memory * 'a t_address) : bool =
    let p : (int list) ref = ref (!(mem.freel))
       and found : bool ref = ref false
    in
      (
      while not(isempty(!p)) && not(!found)
      do 
        found := (fst(!p) = ad) ; 
        p := rem_fst(!p)
      done ;
      !found
      )
  in
  if ad = null
  then failwith("erreur free : adresse nulle")
  else 
    if not((ad >= 0) && (ad < mem.len))
    then failwith("erreur free : acces hors memoire")
    else 
      if isfree(mem, ad)
      then ()
      else mem.freel := add_fst(!(mem.freel), ad)
;;

let mget(mem, ad : 'a t_memory * 'a t_address) : 'a =
  if not((ad >= 0) && (ad < mem.len))
  then failwith("erreur mem_get : acces hors memoire")
  else mem.mem.(ad)
;;


(* ------------------------ *)
(*    lecture caractere     *)
(* ------------------------ *)

let read_char() : char =
  let s : string ref = ref "" and the_end : bool ref = ref false in
    (
    while not(!the_end) 
    do
      s:= read_line() ; 
      if String.length(!s) = 0
      then 
        (
        print_string("erreur read_char : aucun caractere saisi") ;
        print_newline() ;
        )
      else the_end := true;
    done ;
    (!s).[0] ;
    )
;;

(* ------------------------- *)
(* conversion char -> string *)
(* ------------------------- *)

let string_of_char(c : char) : string = Char.escaped c ;;


(* ------------------------ *)
(*    longueur string       *)
(* ------------------------ *)

let string_length(s : string) : int = String.length s ;;


(* ------------------------------ *)
(* conversion string -> char list *)
(* ------------------------------ *)

let charlist_of_string(s : string) : char list =
  let myl : (char list) ref = ref (empty()) 
    and indmax : int = string_length(s) - 1
  in
    (
    for i = indmax downto 0
    do myl := add_fst(!myl, s.[i])
    done ;
    !myl
    )
;;

(* ------------------------------ *)
(* conversion char list -> string *)
(* ------------------------------ *)

let string_of_charlist(l : char list) : string =
  let n : int = len(l) and myl : (char list) ref = ref l in
  let indmax : int = n - 1 and b : bytes = Bytes.create n in
    (
    for i = 0 to indmax
    do
      Bytes.set b i (fst(!myl)) ;
      myl := rem_fst(!myl)
    done ;
    Bytes.to_string b
    )
;;



(* ------------------------ *)
(*  pause durant execution  *)
(* ------------------------ *)
(* ------------------------ *)
let wait(n : int) : unit =
 Unix.sleep(n)
;;



(* ---------------------------- *)
(* fonctions graphiques de base *)
(* ---------------------------- *)

let open_graph(dx, dy : int * int) : unit = 
  if Sys.os_type = "Unix" then  
    let s = ":0 "^string_of_int(dx)^"x"^string_of_int(dy) in
      Graphics.open_graph s
  else
    let s = string_of_int(dx)^"x"^string_of_int(dy) in
      Graphics.open_graph s
;;

let close_graph() : unit = Graphics.close_graph() ;;

let clear_graph() : unit = Graphics.clear_graph() ;;

let resize_window(x, y : int * int) : unit = Graphics.resize_window x y ;;


let moveto(x, y : int * int) : unit = Graphics.moveto x y ;;

let lineto(x, y : int * int) : unit = Graphics.lineto x y ;;

let plot(x, y : int * int) : unit = Graphics.plot x y ;;

let current_point() : int * int = Graphics.current_point() ;;

let draw_poly_line(t : (int * int) array) : unit = Graphics.draw_poly_line t ;;

let draw_circle(x, y, r : int * int * int) : unit = Graphics.draw_circle x y r ;;

let draw_ellipse(x, y, dx, dy : int * int * int * int) : unit = 
          Graphics.draw_ellipse x y dx dy 
;;

let draw_rect(x, y, dx, dy : int * int * int * int) : unit = 
  if Sys.os_type = "Unix" then  
    Graphics.draw_rect x y (dx- 1) (dy - 1)
  else
    Graphics.draw_rect x (y+1) (dx-1) (dy-1)
;;

let fill_rect(x, y, dx, dy : int * int * int * int) : unit = 
  if Sys.os_type = "Unix" then  
    Graphics.fill_rect x y (dx- 1) (dy - 1)
  else
    Graphics.fill_rect x y dx dy
;;

let fill_poly(t : (int * int) array) : unit = Graphics.fill_poly t ;;

let fill_circle(x, y, r : int * int * int) : unit = Graphics.fill_circle x y r ;;


let fill_ellipse(x, y, dx, dy : int * int * int * int) : unit = 
          Graphics.fill_ellipse x y dx dy 
;;

let set_line_width(e : int) : unit = Graphics.set_line_width e ;;

let draw_string(s : string) : unit = Graphics.draw_string s ;;

let set_text_size(n : int) : unit = 
  let s = "-*-courier-medium-r-*-*-"^string_of_int(n)^"-*"
  in Graphics.set_font s ;;



type t_color = Graphics.color ;;

let black : t_color = Graphics.black ;;
let blue : t_color = Graphics.blue ;;
let red : t_color = Graphics.red ;;
let green : t_color = Graphics.green ;;
let white : t_color = Graphics.white ;;
let yellow : t_color = Graphics.yellow ;;
let cyan : t_color = Graphics.cyan ;;
let magenta : t_color = Graphics.magenta ;;
let grey : t_color = 128 * 256 * 256 + 128 * 256 + 128 ;;

let color_of_rgb(r, g, b : int * int * int) : t_color =
  let valid(x : int) : bool = ((0 <= x) && x <= 255) in
    if not(valid(r)) ||  not(valid(g)) || not(valid(b))
    then failwith("erreur color_of_rgb : valeurs invalides")
    else Graphics.rgb r g b
;;



let set_color(color : t_color) : unit = Graphics.set_color color ;;

(* ------------------------ *)
(*   controle evenements    *)
(* ------------------------ *)


let key_pressed() : bool =
  Graphics.key_pressed()
;;

let read_key() : char =
  Graphics.read_key()
;;

let mouse_pos() : int * int =
  Graphics.mouse_pos()
;;

let button_down() : bool = 
  Graphics.button_down()
;;

(* ----------------------------- *)
(* types et fonctions graphiques *)
(*  passage espace de travail a  *)
(*       fenetre graphique       *)
(* ----------------------------- *)
                   
(* -- espace de travail float -- *)

type t_float_space = {f_minx : float ; f_miny : float ;
                                 f_maxx : float ; f_maxy : float} ;;
type t_int_space = {i_minx : int ; i_miny : int ; 
                                 i_maxx : int ; i_maxy : int} ;;
type t_point_float = {x : float ; y : float} ;;
type t_float_graphic_parameter = {origin_x : float ; origin_y : float ; 
             translation_x : float ; translation_y : float ; 
             dilation_x : float ; dilation_y : float} ;;
let init_float_graphic_parameter(work, display : t_float_space * 
                           t_int_space) : t_float_graphic_parameter = 
  let minx : float = float_of_int(display.i_minx)  
       and maxx : float = float_of_int(display.i_maxx) 
       and miny : float = float_of_int(display.i_miny) 
       and maxy : float = float_of_int(display.i_maxy) 
  in 
      {origin_x  = work.f_minx ; origin_y = work.f_miny ; 
      translation_x = minx ; translation_y = miny ; 
      dilation_x = (maxx -. minx) /. (work.f_maxx -. work.f_minx) ;
      dilation_y = (maxy -. miny) /. (work.f_maxy -. work.f_miny)}
;;
let mydilation_x_float(x, param : float * t_float_graphic_parameter) : float =
  x *. param.dilation_x
;;
let mydilation_y_float(y, param : float * t_float_graphic_parameter) : float =
  y *. param.dilation_y
;;
let mygraphic_x_float(x, param : float * t_float_graphic_parameter) : int =
  int_of_float(mydilation_x_float(x -. param.origin_x, param) +. 
                                  param.translation_x)
;;
let mygraphic_y_float(y, param : float * t_float_graphic_parameter) : int =
  int_of_float(mydilation_y_float(y -. param.origin_y, param) +. 
                                  param.translation_y)
;;
let myplot_float(x, y, param : float * float * t_float_graphic_parameter) : unit =
  plot(mygraphic_x_float(x, param), mygraphic_y_float(y, param))
;;
let mydraw_rect_float(x, y, dx, dy, param : float * float * float * float * 
                                       t_float_graphic_parameter) : unit =
  let px : int = mygraphic_x_float(x, param) 
     and py : int = mygraphic_y_float(y, param)
     and pdx : int = int_of_float(mydilation_x_float(dx, param)) 
     and pdy : int = int_of_float(mydilation_y_float(dy, param))
  in
    draw_rect(px, py, pdx, pdy)
;;
let mydraw_circle_float(x, y, r, param : float * float * float * 
                                       t_float_graphic_parameter) : unit =
  if (param.dilation_x = param.dilation_y)
  then draw_circle(mygraphic_x_float(x, param), mygraphic_y_float(y, param), 
        int_of_float(mydilation_x_float(r, param)))
  else draw_ellipse(mygraphic_x_float(x, param), mygraphic_y_float(y, param), 
    int_of_float(mydilation_x_float(r, param)), 
    int_of_float(mydilation_y_float(r, param)))
;;
let mymoveto_float(x, y, param : float * float * t_float_graphic_parameter) : unit =
  moveto(mygraphic_x_float(x, param), mygraphic_y_float(y, param))
;;
let mylineto_float(x, y, param : float * float * t_float_graphic_parameter) : unit =
  lineto(mygraphic_x_float(x, param), mygraphic_y_float(y, param))
;;
let mydraw_polyline_float(cur, param : t_point_float array * 
                               t_float_graphic_parameter) : unit =
  let indmax : int = arr_len(cur) - 1 in
    (
    mymoveto_float(cur.(0).x, cur.(0).y, param) ;
    for i = 1 to indmax
    do mylineto_float(cur.(i).x, cur.(i).y, param) 
    done
    )
;;
let mydraw_polyline_xy_float(curx, cury, param : float array * float array * 
                               t_float_graphic_parameter) : unit =
  let indmax : int = arr_len(curx) - 1 in
    (
    mymoveto_float(curx.(0), cury.(0), param) ;
    for i = 1 to indmax
    do mylineto_float(curx.(i), cury.(i), param) 
    done
    )
;;


(* -- espace de travail int -- *)

type t_point_int = {x : int ; y : int} ;;
type t_int_graphic_parameter = {origin_x : int ; origin_y : int ; 
             translation_x : int ; translation_y : int ; 
             dilation_x_num : int ; dilation_x_den : int ;
             dilation_y_num : int ; dilation_y_den : int} ;;
let init_int_graphic_parameter(work, display : t_int_space * t_int_space) : 
                                               t_int_graphic_parameter = 
  {origin_x  = work.i_minx ; origin_y = work.i_miny ; 
      translation_x = display.i_minx ; translation_y = display.i_miny ; 
      dilation_x_num = (display.i_maxx - display.i_minx) ; 
      dilation_x_den = (work.i_maxx - work.i_minx) ;
      dilation_y_num = (display.i_maxy - display.i_miny) ; 
      dilation_y_den = (work.i_maxy - work.i_miny)}
;;
let mydilation_x_int(x, param : int * t_int_graphic_parameter) : int =
  (x * param.dilation_x_num) / param.dilation_x_den
;;
let mydilation_y_int(y, param : int * t_int_graphic_parameter) : int =
  (y * param.dilation_y_num) / param.dilation_y_den
;;
let mygraphic_x_int(x, param : int * t_int_graphic_parameter) : int =
  mydilation_x_int(x - param.origin_x, param) + param.translation_x
;;
let mygraphic_y_int(y, param : int * t_int_graphic_parameter) : int =
  mydilation_y_int(y - param.origin_y, param) + param.translation_y
;;
let myplot_int(x, y, param : int * int * t_int_graphic_parameter) : unit =
  plot(mygraphic_x_int(x, param), mygraphic_y_int(y, param))
;;
let mydraw_rect_int(x, y, dx, dy, param : int * int * int * int * 
                                       t_int_graphic_parameter) : unit =
  let px : int = mygraphic_x_int(x, param) 
     and py : int = mygraphic_y_int(y, param) and
     pdx : int = mydilation_x_int(dx, param)
     and pdy : int = mydilation_y_int(dy, param)
  in
    draw_rect(px, py, pdx, pdy)
;;
let mydraw_circle_int(x, y, r, param : int * int * int * 
                                       t_int_graphic_parameter) : unit =
  if (param.dilation_x_num * param.dilation_y_den = 
                param.dilation_y_num * param.dilation_x_den)
  then draw_circle(mygraphic_x_int(x, param), mygraphic_y_int(y, param), 
       mydilation_x_int(r ,param))
  else draw_ellipse(mygraphic_x_int(x, param), mygraphic_y_int(y, param), 
    mydilation_x_int(r, param), 
    mydilation_y_int(r, param))
;;
let mymoveto_int(x, y, param : int * int * t_int_graphic_parameter) : unit =
  moveto(mygraphic_x_int(x, param), mygraphic_y_int(y, param))
;;

let mylineto_int(x, y, param : int * int * t_int_graphic_parameter) : unit =
  lineto(mygraphic_x_int(x, param), mygraphic_y_int(y, param))
;;
let mydraw_polyline_int(cur, param : t_point_int array * 
                               t_int_graphic_parameter) : unit =
  let indmax : int = arr_len(cur) - 1 in
    (
    mymoveto_int(cur.(0).x, cur.(0).y, param) ;
    for i = 1 to indmax
    do mylineto_int(cur.(i).x, cur.(i).y, param) 
    done
    )
;;
let mydraw_polyline_xy_int(curx, cury, param : int array * int array * 
                               t_int_graphic_parameter) : unit =
  let indmax : int = arr_len(curx) - 1 in
    (
    mymoveto_int(curx.(0), cury.(0), param) ;
    for i = 1 to indmax
    do mylineto_int(curx.(i), cury.(i), param) 
    done
    )
;;



(* ----------------------------------- *)
(*  calcul de complexite de fonctions  *)
(* mycomplexity : calcul des tableaux  *)
(* mydraw_complexity : trace de courbe *)
(* ----------------------------------- *)

let time_eval(myfunc, myparam : ('a -> 'b) * 'a) : float = 
  let mem_tm : float = Sys.time() in
    (
    ignore(myfunc(myparam)) ;
    Sys.time() -. mem_tm
    )
;;
let smooth_time_eval(myfunc, myparam, smooth_nb : ('a -> 'b) * 'a * int) : float = 
  let mem_tm : float ref = ref 0.0 and tm_sum : float ref = ref 0.0 in
    (
    for i = 1 to smooth_nb
    do
      mem_tm := Sys.time() ;
      ignore(myfunc(myparam)) ;
      tm_sum := !tm_sum +. (Sys.time() -. !mem_tm)
    done ;
    !tm_sum /. float_of_int(smooth_nb)
    )
;;
let mycomplexity(step_nb, myfunc, myind, myparam, smooth_nb : int * ('a -> 'b) * (int -> int) * (int -> 'a) * int) : float array * float array = 
  let int_index : int array = arr_make(step_nb + 1, 0)
    and float_index : float array = arr_make(step_nb + 1, 0.0)
    and time_arr : float array = arr_make(step_nb + 1, 0.0)
    and nb_div_smooth: float = float_of_int(smooth_nb) 
    and var_param : 'a array = arr_make(step_nb + 1, myparam(myind(0)))
    and memtime : float ref = ref 0.0
  in
    (
    for j = 0 to step_nb
    do
      int_index.(j) <- myind(j) ;
      float_index.(j) <- float_of_int(int_index.(j)) ;
      var_param.(j) <- myparam(int_index.(j)) ;
    done ;
    for i = 1 to smooth_nb
    do
      for j = 0 to step_nb
      do
        memtime := Sys.time() ;
        ignore(myfunc(var_param.(j))) ; 
        time_arr.(j) <- time_arr.(j) +. (Sys.time() -. !memtime) ;
      done ;
    done ; 
    for j = 0 to step_nb
    do time_arr.(j) <- time_arr.(j) /. nb_div_smooth
    done ;
    (float_index, time_arr) ;
    )
;;
let minmax_float_array(t : float array) : float * float =
  let indmax : int = arr_len(t) - 1 in
  let min : float ref = ref 0.0 and max : float ref = ref 0.0 in
    if indmax < 0
    then failwith("erreur minmaxfloatarray : tableau vide") 
    else
      (
      min := t.(0) ; max := t.(0) ;
      for i = 1 to indmax 
      do 
        if !min <= t.(i) then () else min := t.(i) ;
        if !max >= t.(i) then () else max := t.(i)
      done ;
      (!min, !max)
      )
;;
let mydraw_complexity(ind, tm, wd : float array * float array * t_int_space) : unit =
  let indmax : int = arr_len(ind) - 1 in
  let (minind, maxind) : float * float = minmax_float_array(ind) 
    and (mintm, maxtm) : float * float = minmax_float_array(tm) 
  in
  let dind : float = 0.1 *. (maxind -. minind) 
    and dtm : float = 0.1 *. (maxtm -. mintm) 
  in
  let ws : t_float_space = {f_minx = minind -. dind ; f_miny = mintm -. dtm ; 
                   f_maxx = maxind +. 2.0 *. dind ; f_maxy = maxtm +. 2.0 *. dtm}
  in
  let prm : t_float_graphic_parameter = init_float_graphic_parameter(ws, wd) in
    (
    mymoveto_float(0.0 -. dind, 0.0 -. dtm, prm) ; draw_string("(0, 0)") ;
    mymoveto_float(maxind, 0.0 -. dtm, prm) ; draw_string(string_of_float(ind.(indmax))) ;
    mymoveto_float(0.0 -. dind, maxtm, prm) ; draw_string(string_of_float(maxtm)) ;
    mydraw_polyline_xy_float(ind, tm, prm)
    )
;;


