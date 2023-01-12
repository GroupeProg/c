from os import listdir, system

folders = [".","sources"]
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
print(f"Compile GCC for {args}...")
system(f"gcc {args}-o main.exe && main.exe")