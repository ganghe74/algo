import hashlib
m = hashlib.new('sha256')
m.update(input().encode('utf-8'))
print(m.hexdigest())