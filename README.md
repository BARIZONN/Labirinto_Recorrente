# O Labirinto Recorrente

<img height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"/> 

# INTRODUÇÃO

Um menino está perdido em um labirinto e deve explorá-lo aleatoriamente     enquanto tem cuidado com paredes que bloqueiam seu caminho (representadas pelo símbolo '#') e perigos que podem machucá-lo e retirar um ponto de vida (representados pelo símbolo '*').

Cada vez que o menino se move, sua posição diminui em 1, e a cada 4 posições percorridas, ele descansa e recupera um ponto de vida. No entanto, se ele cair de uma das bordas do labirinto, será transportado para uma posição aleatória em outro labirinto aleatório. Durante essa queda, ele perde um ponto de vida e quebra o chão, transformando o terreno em um perigo.

Para concluir o programa, o menino deve retornar à posição inicial depois de ter passado por todas as matrizes ou morrer tentando.

# LÓGICA UTILIZADA
* Para iniciar o programa, é necessário abrir o arquivo "input.data" e ler as informações das matrizes contidas nele. Para isso, a classe Maze contém um método chamado readHeader que extrai as informações do cabeçalho do arquivo e as armazena em uma variável chamada mazeDimensions, que representa a altura e a quantidade de matrizes no arquivo. Em seguida, o método separateMatrix cria matrizes booleanas para rastrear as posições por onde o garoto já passou. O método allocate aloca a memória para a matriz que será operada, e o método getInitialPosition obtém a posição inicial do garoto no labirinto.

* Depois disso, é hora de carregar a matriz do labirinto que será explorada, que é feito pelo método loadMatrix. A movimentação do garoto é realizada pelo método andar, que escolhe aleatoriamente a próxima posição a ser explorada. Antes de mover o garoto, o método testa se a posição é válida, ou seja, se não está bloqueada por uma parede ou se não contém um perigo. Se a posição for válida, o garoto se move para ela. Caso contrário, o método sorteia uma nova posição aleatória.

* Ao final do jogo, quando o garoto já tiver explorado todo o labirinto e voltado para a posição inicial, ou quando ele tiver perdido todos os pontos de vida, o programa imprime os resultados da exploração: a quantidade de casas andadas pelo garoto, a quantidade de casas não exploradas por ele e a quantidade de perigos encontrados. Essa tarefa é realizada pelo método endGame. É importante notar que as casas contendo o símbolo '#' serão computadas como casas não exploradas.

## Movimentação:

* O movimento do personagem no labirinto é controlado pelos métodos "andar" e "testar_pos" da classe Labirinto. O método "andar" contém um loop que só é encerrado quando o personagem não possui mais pontos de vida ou quando ele já explorou todo o labirinto. Em cada iteração do loop, as seguintes ações são executadas:

1. Verificar se o contador de passos do personagem é um múltiplo de 4; se sim, o personagem ganha um ponto de vida.
1. Gerar um número aleatório entre 0 e 7, cada número representando uma posição no labirinto de acordo com a tabela 1 apresentada.
1. O número gerado é então passado para o método "testar_pos", que realiza os seguintes testes:
     - Se a posição escolhida aleatoriamente está fora dos limites da matriz (linha ou coluna < 0 ou maior que a última linha ou coluna), o personagem é teleportado para o centro de outra matriz.
     - Se a posição escolhida contém um asterisco ('*'), o personagem se move para essa posição, incrementa o contador de passos, remove um ponto de vida do personagem, incrementa o contador de perigos, salva a posição como "true" na matriz booleana e salva as matrizes.
     - Se a posição escolhida contém um zero ('0'), o personagem se move para essa posição, salva a posição como "true" na matriz booleana e salva as matrizes.
     - Se a posição escolhida contém um cardinal ('#'), nada acontece e outro número é escolhido aleatoriamente.
  
Para todos os outros casos, o personagem se move para a posição escolhida, incrementa o contador de passos, subtrai 1 do número presente naquela posição, salva a posição como "true" na matriz booleana e salva as matrizes.
| Número | Posição                    |
|:--------|----------------------------|
| 0      | Direita                    |
| 1      | Diagonal Baixo-Direita     |
| 2      | Baixo                      |
| 3      | Diagonal Baixo-Esquerda    |
| 4      | Esquerda                   |
| 5      | Diagonal Cima-Esquerda     |
| 6      | Diagonal Superior Esquerda |
| 7      | Cima                       
## Exibindo o trajeto:


Após o término da exploração do labirinto pelo garoto, serão exibidos os seguintes resultados:

* Se o garoto conseguiu concluir o labirinto ou se ele morreu no caminho;
* A quantidade total de casas percorridas pelo garoto;
* O número de casas que ainda não foram exploradas pelo garoto;
* O total de perigos que o garoto encontrou durante sua jornada.

# EXEMPLO

## ENTRADA:


|   |   |   |   |   |
|---|---|---|---|---|
| 3 | 4 | 5 | # | 2 |
| 1 | 2 | # | 3 | # |
| # | * | * | 1 | 3 |
| 4 | * | * | 2 | 1 |
| 5 | * | 5 | # | # |
|   |   |   |   |   |
| 1 | 1 | * | * | * |
| 1 | # | 3 | # | 3 |
| # | 3 | # | # | # |
| # | 1 | 2 | * | # |
| * | 3 | 1 | # | 4 |

## Saída:

    Total de passos : 16 
    Total de casas exploradas: 17
    Total de itens consumidos: 11 
    Total perigos encontrados: 12 
    Tempo de execução: 102 ms.

| 3 | 4 | 5 | * | * |
|---|---|---|---|---|
| * | 2 | # | 3 | # |
| # | * | * | 1 | 3 |
| 4 | * | * | 2 | 1 |
| 5 | * | 5 | # | # |
|   |   |   |   |   |
| * | 0 | * | * | * |
| 1 | # | 2 | * | 3 |
| # | 3 | # | # | # |
| # | 1 | 2 | * | # |
| * | 3 | 1 | # | 4 |

# CONCLUSÃO

O problema de computação conhecido como "labirinto recorrente" envolve a exploração de um labirinto que pode ter uma configuração recorrente, ou seja, o mesmo padrão de caminhos e obstáculos se repete em diferentes partes do labirinto. Este problema é interessante porque pode levar a soluções inesperadas e ineficientes quando não é tratado adequadamente.

Uma das principais conclusões que podemos tirar é que a exploração de um labirinto recorrente requer uma abordagem cuidadosa, a fim de evitar a repetição desnecessária de cálculos ou a exploração interminável de um ciclo infinito. Também é importante considerar a eficiência do algoritmo escolhido para explorar o labirinto, pois um algoritmo mal projetado pode levar a um tempo de execução muito longo ou mesmo a um erro de memória.

Além disso, o problema do labirinto recorrente destaca a importância do uso de estruturas de dados eficientes e algoritmos de busca bem projetados. Por exemplo, o uso de matrizes booleanas pode ser uma maneira eficaz de rastrear quais partes do labirinto já foram exploradas, e o uso de algoritmos de busca inteligentes, como a busca em largura ou a busca em profundidade, pode ajudar a encontrar o caminho mais curto ou mais seguro através do labirinto.

# COMPILAÇÃO E EXECUÇÃO


| Comando      | Função                                                                                   |
|--------------|------------------------------------------------------------------------------------------|
| `make clean` | Apaga a última compilação realizada contida na pasta build                               |
| `make`       | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build. |
| `make run`   | Executa o programa da pasta build após o programa já estar compilado                     |

--------
### Daniel Couto Fonseca;

