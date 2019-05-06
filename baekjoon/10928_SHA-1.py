import hashlib
m = hashlib.new('sha1')
m.update(input().encode('utf-8'))
print(m.hexdigest())