from os import listdir, system

folders = [".","sources", "mini_projet_shaya", "mini_projet_kaez"]
authorized = ['.h', '.c']
files = []


for i in folders:
    for j in listdir(i):
        for k in authorized:
            if j.endswith(k):
                files.append(i+"/"+j)

args = ""
for i in files:
    args += i + " "

print(f"Compile GCC for {args}")
system(f"gcc -x c {args}-o main.exe && main.exe")
print("\n")