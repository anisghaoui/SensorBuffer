import matplotlib.pyplot as plt
import re
i=0

valeur =[]
vector =[]
liste  =[]
maplist=[]

if __name__ == '__main__':
	with open('timemeasure.txt','r') as f:
			content = f.readlines()
			for line in content:
				to_cast =re.findall(r"[-+]?\d*\.\d+|\d+",line)
				to_cast = [float(i) for i in to_cast]
				#valeur.append(to_cast[0])
				vector.append(to_cast[1])
				liste.append(to_cast[2])
				maplist.append(to_cast[3])
	valeur =[2**i for i in range(0,20)]
	plt.plot(valeur[:20],vector[:20])
	plt.plot(valeur[:20],liste[:20])
	plt.plot(valeur[:20],maplist[:20])
	plt.xlabel('nombre de mesures pour 10 capteurs')
	plt.ylabel('temps écoulé(s)')
	plt.grid(1,'major','both')
	plt.legend(['vector','list','Map List'])

	plt.show()