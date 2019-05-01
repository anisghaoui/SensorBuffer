import matplotlib.pyplot as plt
import re
i=0

valeur =[]
vector =[]
liste  =[]
maplist=[]

if __name__ == '__main__':
	with open('timing.txt','r') as f:
			content = f.readlines()
			for line in content:
				to_cast =re.findall(r"[-+]?\d*\.\d+|\d+",line)
				to_cast = [float(i) for i in to_cast]
				valeur.append(2**to_cast[0])
				vector.append(to_cast[1])
				liste.append(to_cast[2])
				maplist.append(to_cast[3])
	plt.plot(valeur,vector,'-+')
	plt.plot(valeur,liste,'-+')
	plt.plot(valeur,maplist,'-+')
	plt.xlabel('Nombre de mesures sur 100 différents capteurs')
	plt.ylabel('Temps écoulé(s)')
	plt.grid(1,'major','both')
	plt.legend(['Vector','List','Map List'])

	plt.show()