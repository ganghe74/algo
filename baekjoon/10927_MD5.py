import hashlib
m = hashlib.new('md5')
m.update(input().encode('utf-8'))
print(m.hexdigest())