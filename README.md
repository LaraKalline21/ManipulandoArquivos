# Compilar arquivo
- gcc "nome_arquivo" -o "nome_saída"
# Rodar arquivo
- ./"nome_saida".exe
## argc
- quantidade de argumentos
## argv
- valores dos argumentos
# Abrir arquivo externo
> fopen(argv[1], "r"); 
- r: read, lê arquivo
- w: write, escreve arquivo
- a: append, se já existir: adiciona, se não: cria e adiciona
# strtok
- lê ate achar o caracter, pega a primeira parte antes desse caracter
# _strdup
- separa armazenamento com malloc e usa a funcao strcpy para copiar a string
# atof
- transforma string em float
