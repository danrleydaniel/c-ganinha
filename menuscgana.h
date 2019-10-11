typedef struct usuario Usuario;

struct usuario{
  char nome[80];
  char email[40];
  char cpf[15];
  int dia;
  int mes;
  int ano;
  int numNativo;
  char* signos; 
  char* china;
  char status;
};

void logotipoPrincipal(void); //Mostra o logotipo do programa principal
void logoCadastrarCliente(void); //Mostra o logotipo do menu Cadastrar Cliente
void logoMenuClientes(void); //Mostra o logotipo do Menu Clientes geral
char mainMenu(void); //Menu principal do programa
char menuClientes(void); //Mostra o menu da área dos clientes
Usuario* cdCliente(void); //Cadastra um novo usário
void listarClientes(Usuario*); //Lista os clientes que estão cadastrados (ainda sob implementação)
char menuPrevisoes(void); //Mostra o menu da área de previsões
void creditos(void); //Informações sobre os desenvolvedores e o programa
