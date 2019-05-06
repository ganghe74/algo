import hashlib
m = hashlib.new('md5-sha1')
m.update(input().encode('utf-8'))
print(m.hexdigest())