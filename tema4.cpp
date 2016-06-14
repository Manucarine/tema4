// Tema 4 - Jogo das Moedas
#include <iostream>
#include <string>
using namespace std;

/*
* Retire 1, 3 ou 4 moedas.
* Quem tirar a �ltima ganha!
*
* O primeiro a chegar em 3 (tr�s) vit�rias ganha o jogo.
*
* O c�digo est� incompleto!
* 1. Leia o c�digo (linha a linha) e seus coment�rios.
* 2. Preencha os coment�rios em ----- MAI�SCULO ----- com o c�digo que est� faltando.
* 3. Teste!
* 4. Repita 2 e 3.
*
* Se necess�rio, use uma folha para lhe auxiliar! Copie o nome das vari�veis e seus valores.
*
* Boa sorte!
*
*/
int main()
{
	// O jogo � feito para 2 jogadores.
	string jog1, jog2;

	// Diz qual o jogador da vez: 1 ou 2.
	int jogador_da_vez = 1;
	// Come�a sempre com o Jogador 1.

	// O vencedor de cada rodada ganha 1 ponto. Quem chegar a 3 pontos primeiro vence o jogo.
	int pont_jog1 = 0, pont_jog2 = 0;

	// Total de moedas por partida.
	int moedas = 10;
	// Quantidade de moedas que o jogador quer retirar.
	int qnt_moedas_tira;

	// ------ RECEBER O NOME DOS JOGADORES 1 E 2 ------
	cout << "DIGITE O NOME DO JOGADOR 1: " << endl;
	cin >> jog1;
	cout << "DIGITE O NOME DO JOGADOR 2: " << endl;
	cin >> jog2;

	// Limpa a tela e inicia o jogo.
	system("cls");
	bool sair = false;

	// Enquanto sair for falso.
	while (!sair)
	{
		// ------ MOSTRAR O PLACAR EM TELA COMO NA IMAGEM ------
		cout << jog1 << " " << pont_jog1 << " x " << pont_jog2 << " " << jog2 << endl;

		// ------ MOSTRAR AS MOEDAS EM TELA COMO NA IMAGEM ------
		for (int cont = 0; cont<moedas; cont++)
		{
			cout << " @ ";
		}
		/*
		foi acrescentada esta linha para que pudesse ser dado um espa�oe entre as moedas e a vez
		do jogador <3 :D :D
		*/
			cout << endl;
		// Diz qual o jogador que est� jogando.
		cout << "Vez do Jogador " << jogador_da_vez << endl;

		// Recebe quantas moedas devem ser tiradas pelo jogador.
		cout << "Digite 1, 3 ou 4 para tirar moedas." << endl;
		cin >> qnt_moedas_tira;

		// Verifica se a quantidade de moedas retiradas � valida.
		if (qnt_moedas_tira == 1 || (qnt_moedas_tira == 3 && moedas >= 3) || (qnt_moedas_tira == 4 && moedas >= 4))
			// ------ ESSA CONDI��O POSSUI ALGUM PROBLEMA? VERIFIQUE! -----
			// Teste o programa depois de feito e veja se tem algum erro!	
		{
			// ------ RETIRAR AS MOEDAS ------
			moedas = moedas - qnt_moedas_tira;

			system("cls");

			// V� se o jogo terminou.
			if (moedas == 0)
			{
				// Mostra se o Jogador 1 ou o 2 ganhou.
				cout << "Ganhou Jogador " << jogador_da_vez << endl;

				// ------ AUMENTAR A PONTUACAO DO JOGADOR QUE GANHOU ------
				if (jogador_da_vez == 1) pont_jog1 = pont_jog2 + 1;
				else if (jogador_da_vez == 2) pont_jog2 = pont_jog2 + 1;

				// Se nenhum dos jogadores chegou em 3 pontos ainda, ent�o reinicia a rodada. Se n�o, sai do jogo.
				if (pont_jog1 < 3 && pont_jog2 < 3) moedas = 10;
				else sair = true;
				
				// ------ POR QUE ESSA LINHA � NECESS�RIA? -----
				// Teste com e sem ela, e comente!
				system("pause");

				/*
				caso este comando n�o estivesse apresentado nesta linha, n�o teria como os jogadores saberem quem foi o 
				vencedor do jogo, por tanto se faz necessario uma pausa durante a execulss�o para que possa ser mostrado 
				quem foi o ganhador, ou vice ver.
				*/
			}
			// Se n�o, troca para o pr�ximo jogador.
			else
			{
				// ------ TROCAR DE JOGADOR (DO 1 PARA O 2 E VICEVERSA) ------
				/* inicio no 1, se jog 1 terminou ent�o troco pro 2 (manu coment)
				se estava no dois ent�o troco pro um
				*/

				if (jogador_da_vez == 1) jogador_da_vez = 2;
				else if (jogador_da_vez == 2) jogador_da_vez = 1;
				 
			}
		}
		else
		{
			/* Se o jogador digitou uma quantidade de moedas invalida (ou seja, diferente de 1, 3 ou 4)
			* ent�o mostra uma mensagem de erro. */
			cout << "Numero de moedas invalido. Tente novamente (Digite 1, 3 ou 4)." << endl;

			/* manu comentario
			se por ventura o usuario digitar um numero que nao esteja correspondente aos que pedem para ser digitados 
			e retirados da quantidade de moedas atual, esta linha avisar� que o processo n�o podera ser concluido pois
			o numero digitado pelo usuario esta invalido
			*/

			// ------ POR QUE ESSA LINHA � NECESS�RIA? -----
			/* pq se nao tivesse esta linha, caso o usuario digitasse um numero que nao esta na mecanica abordada no jogo
			n�o teria como ele saber o pq do erro durante o processo de jogabilidade, por tanto para este caso foi necessario
			o uso do comando "pause" que nada mais eh do que pausar para que o usuario possa ver onde foi o erro.
			*/
			system("pause");
		}

		// ------ LIMPAR A TELA PARA A PR�XIMA RODADA ------
		system("cls");
		// Coloque o c�digo aqui!
	}

	// Ao final das rodadas, mostra o nome do jogador com a maior pontua��o.
	if (pont_jog1 > pont_jog2) cout << "Jogador 1 " << jog1 << " Venceu as tres rodadas!" << endl;
	else cout << "Jogador 2 " << jog2 << " Venceu as tres rodadas!" << endl;
	// Ser� aquele que atingir 3 pontos.

	return 0;
}
