import random


numbers = [2**i for i in range(0,32)]

number_of_sensors = 100

if __name__ == '__main__':
	for i in range(24):
		with open('largedata'+str(i)+'.txt','w') as f:
			for x in range(0,2**i):
				order = random.randint(0,1)
				f.write(str(order)+' '+ str(random.randint(0,number_of_sensors)))
				if order == 0 :
					f.write(' '+str(random.random()))
				f.write('\n')