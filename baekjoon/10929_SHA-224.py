import hashlib
m = hashlib.new('sha224')
m.update(input().encode('utf-8'))
print(m.hexdigest())