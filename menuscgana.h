typedef struct usuario Usuario;
typedef struct consultor Consultor;

struct usuario{
  char nome[80];
  char email[40];
  char cpf[15];
  int dia;
  int mes;
  int ano;
  char status;
};

struct consultor{
  char nome[80];
  char cpf[15];
  int numNativo;
  char* signos;
  char* china;
};

void logotipoPrincipal(void); //Mostra o logotipo do programa principal
void logoCadastrarCliente(void); //Mostra o logotipo do menu Cadastrar Cliente
void logoMenuClientes(void); //Mostra o logotipo do Menu Clientes geral
void logoListaClientes(void); //Mostra o logotipo do Menu Listar Clientes
void logoBuscarCliente(void); //Mostra o logotipo do Menu Buscar Cliente
void logoDeletarCliente(void); //Mostra o logotipo do Menu Deletar Cliente
void exibeCliente(Usuario*); //Exibe um usuário em específico
char mainMenu(void); //Menu principal do programa
char menuClientes(void); //Mostra o menu da área dos clientes
void cdCliente(void); //Cadastra um novo usuário
void gravaUsuario(Usuario*); //Grava os dados de um usuário num arquivo
void listarClientes(void); //Lista os clientes que estão cadastrados (ainda sob implementação)
void buscarCliente(void); //Busca um cliente
void deletarCliente(void);
char menuPrevisoes(void); //Mostra o menu da área de previsões
void creditos(void); //Informações sobre os desenvolvedores e o programa
