import hashlib
m = hashlib.new('sha512')
m.update(input().encode('utf-8'))
print(m.hexdigest())