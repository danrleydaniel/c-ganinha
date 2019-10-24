int chartoint(char); //Transforma char para inteiro
char inttochar(int); //Transforma inteiro para char
int numerologia(int, int, int); //Função que retorna o "número nativo" do usário
char * horoscopo(int); //Função que retorna o animal no horóscopo chinês correspondente à data de nascimento do usuário
char * signo(int, int, int); //Função que retorna o signo de acordo com a data de nascimento do usuário
int bissexto(int); //Função do professor Flavius Gorgônio que checa se um ano é bissexto
int dataValida(int, int, int); //Função do professor Flavius Gorgônio que checa se uma data fornecida pelo usário é válida
int validaCpf(char *); //Função que verifica a validez de um CPF dado pelo usário
int validaEmail(char *); //Função que verifica a validez de um email dado pelo usário
//Funções que mostram as características de cada signo:
void ariesCarac(void);
void touroCarac(void);
void gemeosCarac(void);
void cCarac(void);
void leaoCarac(void);
void virgemCarac(void);
void libraCarac(void);
void escorpiaoCarac(void);
void sagiCarac(void);
void capricornioCarac(void);
void aquarioCarac(void);
void peixesCarac(void);
void signCarac(char*); //Recebe como parâmetro o signo e printa as características dele
//Funções que mostram as características de cada signo:
void ratoCarac(void);
void boiCarac(void);
void tigreCarac(void);
void coelhoCarac(void);
void dragaoCarac(void);
void cobraCarac(void);
void cavaloCarac(void);
void cabraCarac(void);
void macacoCarac(void);
void galoCarac(void);
void caoCarac(void);
void porcoCarac(void);
void animalCarac(char*); //Recebe como parâmetro um animal do horóscopo chinês e printa suas características
