import random


numbers = [2**i for i in range(0,32)]

number_of_sensors = 100

if __name__ == '__main__':
	for i in range(32):
		with open('largedata'+str(i)+'.txt','w') as f:
			for x in range(0,2**i):
				f.write(str(random.randint(0,number_of_sensors))+' '+str(random.random()) +'\n')