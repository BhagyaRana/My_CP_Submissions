from sys import stdin, stdout


def main():
    n = int(input())
    while n > 0:
        str = input()
        ans = []
        x = str.replace("//", "$")
        list1 = x.split("/")
        # print(x)
        list1 = list(filter(None, list1))
        # print(list1)
        for k in list1:
            if '$' not in k:
                ans.append(k)
        print(len(ans))
        for z in ans:
            print(z)
        n -= 1


if __name__ == "__main__":
    main()
