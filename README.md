# Agenda (Trabalho Para Materia de Sistema Operacional)

Um programa em C para gerenciar uma lista de contatos pessoais com funcionalidades básicas de CRUD (Create, Read, Update, Delete).

## 📋 Funcionalidades

- ✅ **Adicionar contatos** - Insira nome e telefone
- 🔍 **Pesquisar contatos** - Busque contatos pelo nome
- ❌ **Excluir contatos** - Remova contatos existentes
- 💾 **Persistência de dados** - Os contatos são salvos automaticamente em arquivo
- 🎯 **Interface simples** - Menu interativo fácil de usar

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador GCC instalado
- Sistema operacional Linux/Unix ou Windows com ambiente de desenvolvimento C

### Compilação
```bash
gcc -o catalogo_contatos main.c
```

### Execução
```bash
./catalogo_contatos
```

## 📁 Estrutura do Projeto

```
catalogo-contatos/
│
├── main.c                 # Código fonte principal
├── contatos.txt          # Arquivo de dados (gerado automaticamente)
└── README.md             # Este arquivo
```

## 🎮 Como Usar

1. **Adicionar Contato**: Selecione a opção 1 no menu e informe nome e telefone
2. **Pesquisar Contato**: Opção 2 - digite o nome do contato a ser buscado
3. **Excluir Contato**: Opção 3 - informe o nome do contato a ser removido
4. **Salvar e Sair**: Opção 4 - salva todas as alterações e encerra o programa

## ⚙️ Especificações Técnicas

- **Linguagem**: C
- **Armazenamento**: Arquivo binário (`contatos.txt`)
- **Capacidade**: Até 100 contatos
- **Estrutura de dados**: Array de structs
- **Persistência**: Os dados são carregados automaticamente na inicialização

## 🛠️ Estrutura do Código

### Principais Funções

- `adicionarContato()` - Adiciona novo contato à lista
- `pesquisarContato()` - Busca contato pelo nome
- `excluirContato()` - Remove contato existente
- `carregarContatos()` - Carrega contatos do arquivo
- `salvarContatos()` - Salva contatos no arquivo
- `removeNovaLinha()` - Utility function para tratamento de strings

### Estrutura de Dados

```c
typedef struct {
    char nome[50];
    char telefone[20];
} Contato;
```

## 📊 Formato de Armazenamento

Os contatos são salvos em formato binário no arquivo `contatos.txt`, mantendo a estrutura da struct `Contato`.

## 🐛 Limitações Conhecidas

- Capacidade fixa de 100 contatos
- Não suporta edição de contatos existentes (apenas adição/exclusão)
- Busca case-sensitive
- Não valida formato de telefone

## 🔮 Melhorias Futuras

- [ ] Implementar edição de contatos
- [ ] Adicionar validação de telefone
- [ ] Busca case-insensitive
- [ ] Ordenação de contatos
- [ ] Interface gráfica
- [ ] Exportação para CSV
- [ ] Categorização de contatos

## 👨‍💻 Autor

**Vynicyus Candido**  
- GitHub: [@VynicyusCandido](https://github.com/VynicyusCandido)
- Repositório: [Agenda-Sistema-Operacional](https://github.com/VynicyusCandido/Agenda-Sistema-Operacional)

---

**Nota**: Este projeto foi desenvolvido como parte de estudos em programação C e sistemas operacionais.
