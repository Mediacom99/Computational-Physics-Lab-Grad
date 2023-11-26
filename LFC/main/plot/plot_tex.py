import numpy as np
import matplotlib.pyplot as plt
from scipy import special as sp
#from mpl_toolkits.axisartist.axislines import AxesZero


"""
Python script per renderizzare il testo tramite latex
"""



#SETTINGS SECTION

plt.style.use('./style_sheet.mplstyle') #To render using TeX

fig = plt.figure(layout='tight')
axs = fig.add_subplot(1,1,1)
#axs.tick_params(axis='both', which='major', labelsize=10)







#MATH FOR PLOT SECTION

'''
#plot k1epsilon(g) fig 5
def func(x):
    return 2*np.exp((np.angle(sp.gamma(complex(1,x))) - np.pi)/x)

lsp = np.linspace(0.000001,6,1000)
a = np.zeros(1000)
for n in range(1000):
    a[n] = func(lsp[n]);
'''


#Setting up vector of data from txt files
x = np.genfromtxt("deltaDati.txt", delimiter=',',dtype=np.longdouble, usecols=0)
y = np.genfromtxt("deltaDati.txt", delimiter=',',dtype=np.longdouble, usecols=1)



#PLOT SECTION

axs.plot(x,y,color='black', linewidth=1)
#axs.plot(lsp, -1 / (lsp*lsp), color='black', linewidth=1)
#axs.vlines(0.25,-16,0.1,color='black',label=r'\epsilon')

#CUSTOMIZE SECTION

#Labels
axs.set_xlabel(r'$g$', fontsize=20, loc='right')
axs.set_ylabel(r'$\epsilon$', fontsize=20, loc='top', rotation='horizontal')
axs.set(xlim=(np.amin(x),np.amax(x)), ylim=(np.amin(y),np.amax(y)))
#axs.set(xlim =(np.amin(x),np.amax(x)),ylim=(-0.2, 0.8))
#axs.set_xscale('log')
#axs.set(xlim=(0,3),ylim=(-17,0))

#Ticks
#plt.yticks(list(plt.yticks()[0]) + [np.pi/4])
#plt.xticks(list(plt.xticks()[0]) + [np.power(10.0,-10.0)])
#plt.yticks([np.pi/4.0, -np.pi/4.0, -np.pi/2.0, 0.0],[r'$\frac{\pi}{4}$',r'$\frac{-\pi}{4}$',r'$\frac{-\pi}{2}$','0'])



#Axis and spines
#axs.xaxis.tick_top()
#axs.xaxis.set_label_coords(-28.0, -0.0)
#axs.xaxis.set_label_position('bottom') 
#axs.spines['bottom'].set_position('zero') #posizione asse x dove x = 0, anche se i dati su y non sono simmetrici
axs.spines['right'].set_visible(False)
axs.spines['top'].set_visible(False)
#axs.spines['bottom'].set_visible(False)
#axs.spines['left'].set_linewidth(3)
#axs.set_title('TITOLone incredibbile', fontsize = 12)
#axs.grid()

#Text
#plt.text(0.25,0.2,r'$\epsilon$', fontsize=15)
#approx = r'$k_{1}\epsilon = 2e^{\frac{[\arg\Gamma(1+ig) - \pi]}{g}}$'
axs.legend([r'$\epsilon(g)\text{ by imposing } k_1=0.1 \text{ constant}$'],prop={'size': 10},loc='upper center')



#SAVING SECTION

plt.savefig('fig8.pdf',format='pdf')
plt.show()