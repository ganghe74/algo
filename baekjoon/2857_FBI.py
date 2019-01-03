agent = []
for i in range(5):
    s = input()
    if s.find("FBI") != -1:
        agent.append(str(i+1))
if len(agent) == 0:
    print("HE GOT AWAY!")
else:
    print(" ".join(agent))