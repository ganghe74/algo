import hashlib
m = hashlib.new('sha384')
m.update(input().encode('utf-8'))
print(m.hexdigest())