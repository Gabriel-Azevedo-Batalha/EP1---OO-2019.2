Bibliotecas necessárias :
-iostream
-vector
-string
-fstream
-sstream
-stdlib.h

Compilar e executar:
    1)make clean (Optativo mas recomendado)
    2)make
    3)make run

Intruções de uso:
    Observações: -Todas as perguntas(S/N) consideram 'S' e 's' "sim" e os demais caracteres "não"
                 -Mesmo quando não especificado, digitar algo não esperado resutará em mensagem de erro (Exceto o caso acima)
		 -Alterar um arquivo manualmente pode gerar erros (Principalmente deletar linhas)

    1)Interface inicial
    -Digitar 1 abre o modo Venda(Linha 9)
    -Digitar 2 abre o modo Recomendação(Linha 33)
    -Digitar 3 abre o modo Estoque(Linha 39)
    -Digitar 4 encerra o programa
    -Outra entrada mostrará uma mensagem de erro ("ERRO : Entrada inválida")

    2)Modo venda 
    -Digitar 1 permite adicionar um produto no carrinho:
        -Digitar um nome válido adiciona o produto no carrinho
        -Caso não haja mais desse produto no estoque será mostrada uma mensagem de erro ("ERRO : Sem o item no estoque")  e retornará ao início do modo Venda
        -Digitar um nome inválido mostra uma mensagem de erro ("ERRO : Não foi possível encontrar o produto") e o programa retorna ao início modo Venda
    -Digitar 2 permite remover um produto do carrinho 
        -Será mostrado o carrinho atual
        -Digitar um nome válido remove o produto no carrinho
        -Digitar um nome inválido mostra uma mensagem de erro ("ERRO : Não foi possível encontrar o produto") e o programa retorna ao início modo Venda
        -Se não houver produtos no carrinho uma mensagem de erro ("ERRO : Não há produtos no carrinho" ) será mostrada e o programa retornará ao início modo Venda
    -Digitar 3 prosseguirá para a compra
        -Se não houver produtos no carrinho uma mensagem de erro ("ERRO : Não há produtos no carrinho" ) será mostrada e o programa retornará ao início modo Venda
        -Se houver produtos no carrinho, o cliente deverá fazer o login(Linha 50) para continuar
            -Se ele for sócio a compra prossegue com desconto
            -Se ele não for sócio será feita perguntado se ele deseja se tornar sócio
                -Se ele aceitar a compra prossegue com desconto e será cobrada uma taxa adicional(Onde o desconto não se aplica)
                -Se ele recusar a compra prossegue sem desconto
        -Ao final da compra será mostrado a lista dos produtos comprados,o preço total,o preço total com desconto,o valor do desconto e o valor da taxa adicional(Se tiver)
        -Terminada a compra, o programa voltará para a tela inicial
    -Digitar 4 sairá do modo Venda
        -Se houverem produtos no carrinho será confirmado se deseja mesmo sair
            -Se sim, o carrinho será esvaziado e o programa volta a tela inicial
            -Se não, o programa volta a tela do modo Venda
    -Outra entrada mostrará uma mensagem de erro ("ERRO : Entrada inválida")

    2)Modo Recomendação
    -O cliente faz o login(Linha 50)
        -Se ele já fez alguma compra na loja, são mostradas as recomendações
        -Se não, é mostrada a mensagem de erro ("ERRO : Cliente não tem histórico de compras")
    -Em seguida o programa retorna a tela inicial

    3)Modo Estoque
    -Digitar 1 permite adicionar uma produto
        -Deverá ser fornecido o nome, o preço, o estoque, e as categorias do produto
            -Ao adicionar uma categoria será perguntado se deseja adicionar mais
            -Categorias não podem ter espaços (O espaço será interpretado como separação de categorias)
            -Se já houver um produto de mesmo nome:
                -O preço será atualizado
                -O estoque será adicionado
                -Para as categorias será perguntado se as novas substituirão as antigas ou se ela serão ignoradas 
    -Digitar 2 faz o programa voltar a tela inicial
    -Outra entrada mostrará uma mensagem de erro ("ERRO : Entrada inválida")

    4)Login
    4.1)O cliente deve fornecer o CPF
        -Se ele for cadastrado continua o login
        -Se ele não for cadastrado o cliente poderá se cadastrar
            -Se ele aceitar e o CPF for válido, o cliente escolhe uma senha e ele prossegue
                -Se o CPF for inválido ele deverá fornecer novamente
            -Se ele recusar uma mensagem de erro ("ERRO : Não foi possível fazer o login" ) será mostrada e o programa retornará a tela inicial (Esvaziando todo carrinho)
    4.2)Em seguida o cliente deve fornecer a senha (Se ele acabou de se cadastrar não é necessário)
        -Se a senha for correta continua o login
        -Se a senha for incorreta o cliente poderá:
            -Digitar a senha novamente
            -Digitar o CPF novamente(Voltando ao primeiro passo)
            -Sair 
                -Se ele sair uma mensagem de erro ("ERRO : Não foi possível fazer o login" ) será mostrada e o programa retornará a tela inicial (Esvaziando todo carrinho)
    4.3)O status de sócio será detectado automaticamente e para o cliente recém cadastrado será falso
