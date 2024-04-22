import matplotlib.pyplot as plt
import numpy as np

y = np.linspace(0, 100, 100)

# Lê os dados do arquivo
with open("data_of_chart.txt", 'r') as arquivo:
    dados = arquivo.read()

partes = dados.split('\n')
insertion = list(partes[0].split())
for i in range(0, len(insertion)): insertion[i] = int(insertion[i])
selection = list(partes[1].split())
for i in range(0, len(selection)): selection[i] = int(selection[i])


# Cria um array numpy a partir dos dados
insertion_np = np.array(insertion)
selection_np = np.array(selection)
print(insertion)

# Cria o gráfico
plt.plot(y, insertion_np, label='Insertion')
plt.plot(y, selection_np, label='Selection')
plt.legend()

# Configura o título e os rótulos dos eixos
plt.title('Gráfico dos Dados')
plt.xlabel('Tamanho da lista')
plt.ylabel('Acessos')



# Mostra o gráfico
plt.show()