#use "ap2inter.ml";;

type 'a t_heap = {arr: 'a array; arlen : int; len : int ref};;

let h_empty (n,p : int*'a): ('a t_heap) =
  {arr = arr_make(n,p); arlen = n; len = ref 0};;

"sa complexité en temps est de O(n), tout dépend du paramêtre n";;

let h_isempty (s : 'a t_heap): bool =
  if !(s.len) = 0
  then true
  else false
;;

"sa complexité en temps est constante et est donc de O(1)";;

let h_exists(n,i : 'a t_heap * int) : bool =
  if h_isempty(n)
  then failwith ("c'est vide / exist")
  else
    if i < !(n.len)
    then true
    else false
  
;;

"sa complexité en temps est constante O(1)";;

let h_root (t,i : 'a t_heap*int): 'a =
  if h_isempty(t)
  then failwith ("c'est vide / root")
  else t.arr.(i)
    
;;

"sa complexité en temps est constante O(1)";;

let h_subleft (t,i : 'a t_heap*int): int =
  if h_isempty(t)
  then failwith ("c'est vide / subleft")
  else i*2 + 1
    
;;

"sa complexité en temps est constante O(1)";;

 let h_subright (t,i : 'a t_heap*int): int =
  if h_isempty(t)
  then failwith ("c'est vide / subright")
  else i*2 + 2
 ;;

"sa complexité en temps est constante O(1)";;

let h_father (t,i,a : 'a t_heap*int*int): int =
  if h_isempty(t)
  then failwith ("c'est vide / father")
  else
    if (i-1)/2 = a
    then a
    else (i-2)/2  
;;

"sa complexité en temps est constante O(1)";;

let rec is_heap_aux(h,i: 'a t_heap*int) : int*bool =
  if h_isempty(h)
  then (0, true)
  else let (l,r): 'a t_heap*'a t_heap = (h_subleft(h),h_subright(h)) in
       if (not(h_isempty(l))&&h_isempty(r))|| (not(h_isempty(r))&&h_isempty(l))
       then (0,false)
       else let (hl,bl): int*bool = is_heap_aux(l) in
            let (hr,br): int*bool = is_heap_aux(r) in
            (hl+1, bl&&br&&(hl=br))
                                          
;;
                                     
let rec is_heap(h: 'a t_heap): bool =
  let (v,b): int*bool = is_heap_aux(h) in b

;;

"au mieux 0(1) au pire O(n)->n+(n+1)";;

let h_rem_lst_leaf(h: 'a t_heap): unit =
  if h_isempty(h)
  then failwith("c'est vide / rem lst leaf")
  else h.len := !(h.len) - 1;;

"cet arbre n'est plus un tas puisque ce n'est plus un arbre complet, il manque une leaf";;

let exchange (h, a, b : 'a t_heap*int*int) :unit =
  if h_isempty(h)
  then failwith("c'est vide / exchange")
  else
    let (c,d) : 'a *'a = (h.arr.(a),h.arr.(b))in
    h.arr.(a) <- d;
    h.arr.(b) <- c;;

let h_insert (s,v :'a t_heap*'a):unit=s.arr.(!(s.len)) <- v;s.len:=!(s.len)+1;;
