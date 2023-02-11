def comp(seq):
    comp_dict = {"A": "T", "T": "A", "C": "G", "G": "C"}
    seq_comp = ""

    for char in seq:
        if char == "A" or char == "T" or char == "G" or char == "C":
            seq_comp = seq_comp + comp_dict[char]
        else:
            seq_comp = seq_comp + "?"
    return seq_comp


def rev(seq):
    seq_rev = "".join(reversed(seq))
    return seq_rev


def noRev(seq):
    i = len(seq) - 1
    seq_rev1 = ""
    cnt = 0
    while i >= 0:
        seq_rev1 = seq_rev1 + seq[i]
        i -= 1
    return seq_rev1


def rev_comp(a):
    tmp = comp(a)
    return rev(tmp)


src = input("DNA sequence : ")
cnvt = int(input("1(comp), 2(Rev), 3(Rev_Comp) : "))

if cnvt >= 1 and cnvt <= 3:
    if cnvt == 1:
         print(src, ">", comp(src))
    elif cnvt == 2:
       print(src, ">", rev(src))
    else:
     print(src, ">", rev_comp(src))

else:
     print("1(comp), 2(Rev), 3(Rev_Comp)!!")
