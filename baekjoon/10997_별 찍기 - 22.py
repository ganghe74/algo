N = int(input())

lines = ["*****",
         "*    ",
         "* ***",
         "* * *",
         "* * *",
         "*   *",
         "*****"]

for _ in range(N-2):
    lines[0] = "* " + lines[0] + "**"
    for i in range(1, len(lines)):
        lines[i] = "* " + lines[i] + " *"
    l = len(lines[0])
    lines.insert(0, "*" + " " * (l-1))
    lines.insert(0, "*" * l)
    lines.append("*" + " " * (l-2) + "*")
    lines.append("*" * l)

if N == 1:
    lines = ["*"]

for line in lines:
    print(line.rstrip())
