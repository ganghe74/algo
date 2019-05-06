# python2
import hashlib
 
string = raw_input()
sha = hashlib.new('sha')
 
sha.update(string)
print sha.hexdigest()