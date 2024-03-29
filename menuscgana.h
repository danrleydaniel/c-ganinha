typedef struct usuario Usuario;
typedef struct noUsuario NoUsuario;

typedef struct consultor Consultor;
typedef struct noConsultor NoConsultor;

typedef struct relatorio Relatorio;

struct usuario{
  char nome[80];
  char email[40];
  char cpf[15];
  int dia;
  int mes;
  int ano;
  char status;
};

struct noUsuario{
  char nome[80];
  char email[40];
  char cpf[15];
  int dia;
  int mes;
  int ano;
  char status;
  NoUsuario* prox;
};

struct consultor{
  char nome[80];
  char cpf[15];
  int numNativo;
  char signos[15];
  char china[9];
  char status;
};

struct noConsultor{
  char nome[80];
  char cpf[15];
  int numNativo;
  char signos[15];
  char china [9];
  char status;
  NoConsultor* prox;
};

struct relatorio{
  char nomeUsuario[80];
  int dia;
  int mes;
  int ano;
  char cpfUsuario[15];
  char acao[27];
};

void logotipoPrincipal(void); //Mostra o logotipo do programa principal
void logoCadastrarCliente(void); //Mostra o logotipo do menu Cadastrar Cliente
void logoMenuClientes(void); //Mostra o logotipo do Menu Clientes geral
void logoListaClientes(void); //Mostra o logotipo do Menu Listar Clientes
void logoBuscarCliente(void); //Mostra o logotipo do Menu Buscar Cliente
void logoDeletarCliente(void); //Mostra o logotipo do Menu Deletar Cliente
void logoEditarCliente(void); //Mostra o logotipo do Menu Editar Cliente
void logoMenuPrevisoes(void); //Mostra o logotipo do Menu Previsões
void logoCadastrarBolaCristal(void); //Mostra o logotipo do Menu Cadastrar na Bola de Cristal
void logoListarConsultores(void); //Mostra o logotipo do Menu Listar Consultores
void logoEditarBolaCristal(void); //Mostra o logotipo do Menu Editar Dados da Bola de Cristal
void logoConsultarCigana(void); //Mostra o logotipo do Menu Consultar Cigana
void logoDeletarConsultor(void); //Mostra o logotipo do Menu Deletar Consultor
void logoRelatorios(void); //Mostra o logotipo do Menu Relatorios
void logoTarotDiario(void); //Mostra o logotipo das cartas de tarot

void consultarCigana(void); //Realiza a consulta com a cigana
void previsaoDiaria(Consultor*); //Realiza a previsão diária com a cigana
void previsao(int); //Recebe um "número da sorte" e printa uma previsão com base nele

void exibeCliente(Usuario*); //Exibe um usuário em específico
char mainMenu(void); //Menu principal do programa
char menuClientes(void); //Mostra o menu da área dos clientes
void cdCliente(void); //Cadastra um novo usuário
void gravaUsuario(Usuario*); //Grava os dados de um usuário num arquivo
void gravaConsultor(Consultor*); //Grava os dados de um consultor num arquivo
void gravaRelatorio(Relatorio*); //Grava os dados de um relatório num arquivo
char menuListarCliente(void); //Mostra as opções para listar os clientes
void listarClientes(void); //Lista os clientes que estão cadastrados
void listaInvertida(void); //Gera uma lista de com a ordem inversa de usuários cadastrados
void exibeListaUsuario(NoUsuario*); //Função auxiliar para a listaInvertida
void buscarCliente(void); //Busca um cliente
char menuEditarCliente(void); //Mostra as opções para editar um cliente
void editarCliente(void); //Edita um cliente
void editaNome(Usuario*, FILE*); //Edita o nome
void editaEmail(Usuario*, FILE*); //Edita o email
void editaDataNascimento(Usuario*, FILE*); //Edita o CPF
void deletarCliente(void); //Deleta um cliente

char menuPrevisoes(void); //Mostra o menu da área de previsões
void cadastraBolaCristal(void); //Cadastra o cliente nas funcionalidades da cigana
void exibeConsultor(Consultor*); //Exibe um consultor em específico
void listarConsultores(void); //Lista os consultores que estão cadastrados
void editarDadosBolaCristal(void); //Edita os dados de algum consultor na bola de cristal
void deletaConsultor(void); //Deleta um consultor
void relatorios(void); //Exibe todos os relatórios gerados
void exibeRelatorio(Relatorio*); //Exibe um relatório em específico
int menuListarConsultor(void); //escolhe o tipo de lista
void listaInvertidaConsultor(void); // lista normal
void listaDiretaConsultor(void); // lista invertida
void listaOrdenadaConsultor(void); // lista direta
void exibeListaConsultor(NoConsultor*); // lista de cadastrados na bola de cristal


void creditos(void); //Informações sobre os desenvolvedores e o programa

void limparArquivos(void); //Responsável por realizar a exclusão física nos arquivos de dados
void exclusaoFisicaUsuarios(void); //Realiza a exclusão física no arquivo de usuários
void exclusaoFisicaConsultores(void); //Realiza a exclusão física no arquivo de consultores
void chamaTarot(void); // função que responsavel por exibir carta de tarot
void liberaLista(NoUsuario*); // libera lista dinamica da memoria (usuarios)
void liberaListaConsultor(NoConsultor*); // libera lista dinamica da memoria (consultores)
void listaDireta(void); // lista direta
void listaOrdenada(void); // lista ordenada
