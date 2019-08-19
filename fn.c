#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numerologia();

int main(void){
    
    int numerologia(void);
    numerologia();

    return 0;
}

int numerologia(void){

    int dia, mes, ano, calc1, num;
    int  diaf=0, mesf=0, anof=0, numf=0, calc1f=0;

    printf("Digite a data de seu aniversário (dia/mês/ano): ");
    scanf("%d/%d/%d",&dia, &mes, &ano);

    if (ano < 0)
        ano *= -1;
    while (ano){
        anof += ano%10;
        ano/=10;
    }

    if (dia < 0)
        dia *= -1;
    while (dia){
        diaf += dia%10;
        dia/=10;
    }

    if (mes < 0)
        mes *= -1;
    while (mes){
        mesf += mes%10;
        mes/=10;
    }

    calc1 = (diaf + mesf);
    if (calc1 < 0)
        calc1 *= -1;
    while (calc1){
        calc1f += calc1%10;
        calc1/=10;
    }

    num = (anof + calc1f);
    if (num < 0)
        num *= -1;
    while (num){
        numf += num%10;
        num/=10;
    }

    if (numf == 1){
        printf("\n");
        printf("Nativo do número 1:\n");
        printf("\n");
        printf("Características Positivas\n");
        printf("\n");
        printf("São pessoas muito positivas, estão sempre pensando pelo lado bom. São\n"); 
        printf("ousados, criativos, autoconfiantes e pioneiros em tudo que fazem. Não\n");
        printf("desistem nunca, são muito obstinados e corajosos. Ambiciosos, buscam a\n");
        printf("sua independência financeira e emocional sempre.líderes natos, prezam\n");
        printf("pela sua individualidade e gostam de comandar.\n");
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("O seu excesso de autoconfiança e seu gosto por comandar podem gerar\n");
        printf("características de prepotência, egocentrismo e autoritarismo.Têm aversão ao\n");
        printf("fracasso, e quando isso acontece pode se tornar até agressivo, ou se render à\n");
        printf("solidão. É muito orgulho e um tanto inflexível quanto aos seus pontos de vista.\n");
        printf("Apesar de ser muito ativo, tem também um forte lado preguiçoso.\n");
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("Gostam de comandar no relacionamento, geralmente tomam a frente das decisões.\n");
        printf("São muito dedicados no amor e nos relacionamentos, o romance é muito importante\n");
        printf("para eles. Mas como tendem a ser egoístas, têm de aprender a controlar para\n");
        printf("deixar que o parceiro também se manifeste neste relacionamento. Estão sempre\n");
        printf("dispostos a experimentar coisas novas, viver aventuras, muita emoção e diversão.\n");
        printf("Os parceiros precisam ser bastante pacientes pois eles se aborrecem facilmente,\n");
        printf("ficam emburrados, mas depois passa e o bom humor volta.\n");
        printf("\n");
    }
    else if (numf == 2){
        printf("\n");
        printf("Nativo do número 2:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("São pessoas extremamente pacientes, atenciosas e solidárias. Trata a tudo e a todos com a\n"); 
        printf("diplomacia, amabilidade e espírito de colaboração que lhe são característicos. São pessoas\n"); 
        printf("muito receptivas, modestas companheiras.\n");  
        printf("\n"); 
        printf("Características Negativas:\n"); 
        printf("\n"); 
        printf("A dualidade característica deste número traz muita indecisão e insegurança aos nativos do\n"); 
        printf("número 2 na numerologia. A submissão, timidez e passividade também são características frequentes.\n"); 
        printf("\n"); 
        printf("Amor e Relacionamentos:\n"); 
        printf("\n"); 
        printf("São excelentes parceiros amorosos. São compreensivos, carinhosos e adora encher o seu parceiro\n");  
        printf("de carinhos e mimos. É um tanto recatado quando o assunto é sexo devido à sua timidez, tem\n");  
        printf("medo de se aventurar no amor. Tem dificuldade em se relacionar com as pessoas de início, mas\n");  
        printf("depois se solta e se torna muito sociável e amável.\n");
        printf("\n"); 
    }
    else if (numf == 3){
        printf("\n");
        printf("Nativo do número 3:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("Quem tem a influência do número 3 tem muito otimismo e bom gosto. São os reis da comunicação,\n"); 
        printf("comunicam-se muito bem e com qualquer pessoa. São pessoas muito sociáveis e cordiais com todos\n");
        printf("ao seu redor. São talentosos pois têm muita criatividade e entusiasmo pelas artes e cultura.\n");
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("O número 3 também provoca nas pessoas o exibicionismo, a vontade de aparecer, a supercialidade\n");
        printf("e a ostentação. Como gosta muito de se comunicar, pode acabar falando demais e ganhar um espírito \n"); 
        printf("fofoqueiro, daqueles que até aumenta a fofoca com uma mentirinha. Certa imaturidade e dispersão\n");
        printf("também sã comuns.\n");
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("Os nativos do número 3 no amor são divertidos e estão sempre dispostos a agradar o seu parceiro,\n"); 
        printf("encarando novidades com entusiasmo. Eles, no entanto, gostam de ter o seu espaço privado para\n"); 
        printf("ficar sozinho de vez em quando e ter contato com amigos e familiares para se sentir completo.\n"); 
        printf("Quando alguém é muito ciumento ou tenta o prender, eles ficam infelizes, inquietos e acabam \n"); 
        printf("pulando fora. Em um relacionamento equilibrado eles são românticos, sedutores, alegres, sociáveis\n"); 
        printf("e transmitem muita confiança para o seu parceiro.\n");
        printf("\n");
    }
    else if (numf == 4){
        printf("\n");
        printf("Nativo do número 4:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("São pessoas muito leais, organizadas, disciplinas e estáveis. Resolvem tudo com base na calma,\n"); 
        printf("trabalho e cautela. São tradicionais, e dedicam sua vida aos outros com muito amor, confiança\n"); 
        printf("e honestidade. Sua franqueza é símbolo da sua verdade. São trabalhadores dedicados.\n"); 
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("São excessivamente rígidos consigo mesmo e com as pessoas ao seu redor, tendendo a ser\n"); 
        printf("demasiado crítico com os outros e magoar as pessoas. Ao mesmo tempo, são inseguros e\n"); 
        printf("precisam da opinião alheia sobre tudo o que vai fazer. Entretanto, é ao mesmo tempo\n");
        printf("cabeça dura, e tem dificuldade em ser flexível. Apega-se muito fácil ao passado, não\n");
        printf("deixa o passado ir embora. É um bocado avarento e conformista.\n");
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("São extremamente perfeccionistas no amor, querem ser os parceiros perfeitos, e para isso\n");
        printf("gostam de seguir fórmulas tradicionais e não inovar muito. São muito constantes, estáveis\n"); 
        printf("e confiáveis quando estão em um relacionamento, mas também não suportam viver em uma relação\n"); 
        printf("estagnada. Se tiver algum problema atrapalhando a harmonia do casal, eles querem conversar\n"); 
        printf("logo e resolver.\n");
        printf("\n");
    }
    else if (numf == 5){
        printf("\n");
        printf("Nativo do número 5:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("Quem é nativo do número 5 tem características empreendedoras e aventureiras. São\n");
        printf("pessoas muito versáteis e que adoram a sua liberdade. São sensuais e inteligentes,\n"); 
        printf("com a curiosidade e a vontade de mudança à flor da pele.\n");  
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("O senso de aventura em excesso gera irresponsabilidade, falta de objetivos na vida,\n"); 
        printf("inquietação e infidelidade em seus relacionamentos. São muitos ímpetos que surgem ao\n"); 
        printf("mesmo tempo, e isso gera ansiedade, instabilidade e impulsividade.\n"); 
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("São pessoas extremamente sensuais e atraentes, possuem magnetismo pessoal que faz\n"); 
        printf("com que tenham diversos pretendentes. Sua sexualidade é intensa, quase agressiva,\n"); 
        printf("cheia de energia. Quando está em um relacionamento costuma se entregar de cabeça,\n"); 
        printf("desde que não cortem com a sua liberdade. Tem tendência a querer ter mais de um\n");
        printf("parceiro ao mesmo tempo ou de fugir à infidelidade.\n");
        printf("\n"); 
    }
    else if (numf == 6){
        printf("\n");
        printf("Nativo do número 6:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("Quem é nativo do número 6 é uma pessoa generosa, conciliadora e muito estável.\n"); 
        printf("São pessoas muito companheiras, que se preocupam com o seu lar, com sua família\n"); 
        printf("e com seus amigos. Tem um senso de justiça e honestidade apuradas. São muito\n"); 
        printf("equilibrados e procuram a harmonia em todas as relações.\n");  
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("São pessoas um tanto acomodadas com a sua vida, e isso costuma gerar problemas\n"); 
        printf("de relacionamento. Gostam de se fazer de vítima e têm espírito de mártir. São\n"); 
        printf("excessivamente ciumentos, guardam mágoas e rancores antigos e têm muita dificuldade\n"); 
        printf("em aceitar a realidade.\n");
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("No sexo, eles aparentam ser pessoas quietas e passivas mas na verdade fazem de\n"); 
        printf("tudo para dar prazer ao seu parceiro. São dominadores e possessivos, por isso\n"); 
        printf("muitas vezes sente-se inseguro em relação aos sentimentos. São muito ciumentos.\n"); 
        printf("Como conciliadores, eles sempre buscam a paz e a harmonia no relacionamento,\n"); 
        printf("tentando sempre resolver as diferenças com calma e muita conversa. São apegados\n"); 
        printf("ao lar e à família, acha importante o contato constante.\n");
        printf("\n");        
    }
    else if (numf == 7){
        printf("\n");
        printf("Nativo do número 7:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("Quem é nativo do número 7 na numerologia tem por característica a tranquilidade,\n"); 
        printf("a intuição apurada, sabedoria e introspecção. São pessoas meticulosas, lógicas,\n"); 
        printf("donos de grande perfeccionismo e autocontrole. Gostam de se aprofundar em tudo o\n");
        printf("que fazem, investigar tudo pois querem ter conhecimentos sobre todas as coisas.\n");
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("Podem se tornar pessoas melancólicas e solitárias. São desligados, não estabelecem\n"); 
        printf("objetivos e acabam se perdendo e esquecendo o sentido da vida. São excessivamente\n");
        printf("críticos e autocríticos. Exigem demais de si mesmo, acaba se excluindo de grupos\n");
        printf("de amigos e familiares.\n");
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("O amor na vida dos nativos do número 7 é algo difícil de definir e compreender.\n");
        printf("Eles têm desinteresse pelas coisas materiais, por isso não se liga a presentes\n");
        printf("e datas. Sua preocupação com o muito espiritual é muito forte, o que o torna um\n");
        printf("companheiro excêntrico. São muito intuitivos e por isso precisam ter momentos\n");
        printf("solitários em sua vida, mas eles sentem falta de ter um companheiro e por isso\n");
        printf("precisam balancear os momentos sozinhos e momentos com companhia. Eles atingem\n");
        printf("níveis extremos de intimidade com os seus parceiros, se jogam de cabeça, mas\n");
        printf(" são propensos a confiar demais e a sofrer decepções amorosas por causa disso.\n");
        printf("\n");   
    }
    else if (numf == 8){
        printf("\n");
        printf("Nativo do número 7:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("Quem nasce sobre a influência do número 8, vem ao mundo com espírito de liderança,\n"); 
        printf("de eficiência e uma pessoa que luta pelo poder e pelo prestígio. São muito ligados\n"); 
        printf("ao sucesso e à riqueza, mas tudo com muita justiça e honestidade. São perseverantes\n"); 
        printf("e não se deixam abater pelas dificuldades. São muito autoconfiantes, verdadeiros e\n"); 
        printf("compreensivos.\n"); 
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("São demasiado ambiciosos, com sede pelo poder e isso gera um materialismo desenfreado.\n"); 
        printf("Em busca dos seus objetivos materiais eles se tornam arrogantes, intolerantes e\n");
        printf("autoritários. Sua teimosia e impaciência geram discórdias.\n");
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("Sua sexualidade é tão intensa que chega a ser agressiva. Adora desafios e tem tendência\n"); 
        printf("a se envolver em relacionamentos complicados. Quando se envolvem são bastante\n"); 
        printf("responsáveis e passam segurança no relacionamento. No entanto, o seu parceiro\n"); 
        printf("não deve se envolver nos seus assuntos de negócios, pois eles se tornam intolerantes,\n"); 
        printf("frios e arrogantes.\n");
        printf("\n"); 
    }
    else if (numf == 9){
        printf("\n");
        printf("Nativo do número 7:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("São pessoas únicas, capazes de sentir o amor universal, algo raro e difícil.\n"); 
        printf("São muito tolerantes, pacientes e generosos. Possuem uma forte espiritualidade\n"); 
        printf("e fé, nada é capaz de abalar sua crença. Tem respeito e carinho por tudo e\n"); 
        printf("por todos.\n"); 
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("Sua fé inabalável gera brecha para o fanatismo religioso, para pessoas que\n"); 
        printf("querem pregar a sua religiosidade o tempo todo e isso incomoda a muitas pessoas.\n"); 
        printf("Eles acabam solitários e se sentindo fracassados. Fazem sacrifícios desnecessários\n"); 
        printf("e depois se arrependem de não ter aproveitado a vida.\n"); 
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("Quando os nativos do número 9 se apaixonam, eles se tornam grandes amantes, dóceis\n");
        printf("e dedicados. O número 9 é o número das pessoas prestativas e bem dispostas.\n"); 
        printf("Sua simpatia e disposição fazem com que eles possam ser dominados facilmente.\n"); 
        printf("Eles gostam de demonstração de amor, e estão sempre fazendo os seus parceiros\n");
        printf("se sentirem amadas. Ele assume os problemas do parceiro para si e quer\n");
        printf("enfrentá-los juntos. Quando infeliz o número nove pode recorrer a táticas de\n");
        printf("abuso emocional e intimidação.\n");
        printf("\n");
    }
    else if (numf == 11){
        printf("\n");
        printf("Nativo do número 7:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("São pessoas idealistas, que seguem a sua intuição e o seu coração o tempo todo.\n"); 
        printf("Possuem paciência inigualável, sabedoria nata e poderes extra sensoriais. São\n"); 
        printf("voltados para os assuntos místicos e possuem senso humanitário acentuado, gostam\n"); 
        printf("de trazer o bem para todos ao seu redor e é reconhecido pela sua simpatia.\n");
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("Suas características de espiritualidade e elevação quando não são bem geridas,\n");
        printf("podem dar brecha para a existência do fanatismo, charlatanismo, pragmatismo e\n");
        printf("cinismo. Há pessoas do número 11 que ficam desorientadas com sua sensibilidade\n"); 
        printf("e intuição, passam a se sentir superiores aos demais, são desonestas,\n");
        printf("preguiçosas e mesquinhas.\n");
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("O onze é um dos números mais românticos de toda a numerologia. Eles idealizam\n"); 
        printf("o relacionamento, só veem o lado bom do seu parceiro e são extremamente atenciosos.\n"); 
        printf("Procuram em seus parceiros um companheiro para a vida e tentam fazê-los feliz\n"); 
        printf("de toda maneira. Costumam ser muito tolerantes em suas diferenças e aceitam as ideias\n"); 
        printf("e opiniões, mesmo que sejam divergentes.\n");
        printf("\n");
    }
    else if (numf == 22){
        printf("\n");
        printf("Nativo do número 7:\n");
        printf("\n");
        printf("Características Positivas:\n");
        printf("\n");
        printf("São pessoas muito generosas, mão aberta, daqueles que não medem esforços para ajudar\n"); 
        printf("quem ele pode. É dono de um raciocínio invejável, muito sagaz e com espírito empreendedor\n"); 
        printf("sabe transformar sonhos em realidade. É otimista e muito leal.\n"); 
        printf("\n");
        printf("Características Negativas:\n");
        printf("\n");
        printf("São pessoas que têm tendências opostas: ou se tornam vaidosos em excesso, ou sofrem de\n"); 
        printf("um complexo de inferioridade de se achar mais feio e pior do que todos ao seu redor.\n"); 
        printf("Falta determinação para concluir os seus projetos e detestam que as pessoas apontem esse\n"); 
        printf("defeito, reage com cinismo.\n"); 
        printf("\n");
        printf("Amor e Relacionamentos:\n");
        printf("\n");
        printf("No amor, os nativos do número 22 da numerologia são pessoas de extremo, é tudo ou nada.\n"); 
        printf("Não se entregam parcialmente, ou gostam demais da pessoa, ou não se envolvem de jeito\n"); 
        printf("nenhum. É preciso ter cuidado com esse lado extremista, pois uma pessoa que é para ele\n");
        printf("o amor de sua vida pode se tornar o seu pior inimigo caso o relacionamento não dê certo.\n");
        printf("\n");
    }
    else
        printf("Data de cascimento não se enquadra na numerologia.");

    return 0;
}

