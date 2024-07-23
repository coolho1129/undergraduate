import time
now = time.localtime()
number=input('주민등록번호 년월일: ')


age = now.tm_year-(int(number[0:2])+1900)+1
print('나이:',age)