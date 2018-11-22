ten = "6789012345"
twelve = "IJKLABCDEFGH"
N = int(input())
print(twelve[N%12] + ten[N%10])