#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_IF(check, ...) do {                           \
    if((check)) {                                           \
        printf("ERROR! \"%s\" [%d]\n", __FILE__,__LINE__);  \
        printf(__VA_ARGS__);                                \
        printf("\n\ni am become death\ndestroyer of terminals\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠆⠜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⠿⠿⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿\n\
⣿⣿⡏⠁⠀⠀⠀⠀⠀⣀⣠⣤⣤⣶⣶⣶⣶⣶⣦⣤⡄⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿\n\
⣿⣿⣷⣄⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡧⠇⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣾⣮⣭⣿⡻⣽⣒⠀⣤⣜⣭⠐⢐⣒⠢⢰⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣏⣿⣿⣿⣿⣿⣿⡟⣾⣿⠂⢈⢿⣷⣞⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣷⣶⣾⡿⠿⣿⠗⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠻⠋⠉⠑⠀⠀⢘⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⣿⡿⠟⢹⣿⣿⡇⢀⣶⣶⠴⠶⠀⠀⢽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⣿⣿⣿⡿⠀⠀⢸⣿⣿⠀⠀⠣⠀⠀⠀⠀⠀⡟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⣿⣿⣿⡿⠟⠋⠀⠀⠀⠀⠹⣿⣧⣀⠀⠀⠀⠀⡀⣴⠁⢘⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿\n\
⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⠗⠂⠄⠀⣴⡟⠀⠀⡃⠀⠉⠉⠟⡿⣿⣿⣿⣿\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢷⠾⠛⠂⢹⠀⠀⠀⢡⠀⠀⠀⠀⠀⠙⠛⠿⢿\n");\
        exit(1);                                            \
    } \
} while(0)


typedef struct {
    void** data;
    size_t len;
    size_t cap;
} Vec;

Vec vec_new(void) { return (Vec){NULL, 0, 0}; }

void vec_push(Vec* v, void* item) {
    if (v->len == v->cap) {
        v->cap = v->cap ? v->cap * 2 : 4;
        v->data = realloc(v->data, sizeof(void*) * v->cap);
    }
    v->data[v->len++] = item;
}

void* vec_get(Vec* v, size_t i) { return v->data[i]; }

void vec_free(Vec* v) { free(v->data); }


#include <stdint.h>

typedef int8_t s8; 
typedef int16_t s16; 
typedef int32_t s32; 
typedef int64_t s64; 

typedef uint8_t u8; 
typedef uint16_t u16; 
typedef uint32_t u32; 
typedef uint64_t u64; 
typedef intptr_t sptr; 
typedef uintptr_t uptr; 

typedef float f32; 
typedef double f64;

typedef u8 b8;
typedef u16 b16;
typedef u32 b32;
typedef u64 b64;

typedef enum {
    PAR_NONE,

    PAR_NAME,
    PAR_NUM,

    PAR_HASH,

    PAR_LESS,
    PAR_GREAT,

    PAR_COLON,
    PAR_SEMI,

    PAR_LPAREN,
    PAR_RPAREN,

    PAR_QUOTE,

    PAR_BSLASH,

    PAR_LBRAC,
    PAR_RBRAC,

    PAR_NEWLINE,
    PAR_EOF
} TokType;

const char* tokTypeNames[] = { 
    "WHATTHEFUCK",

    "NAME",
    "NUM",

    "HASH",

    "LESS",
    "GREAT",

    "COLON",
    "SEMICOLON",

    "LPAREN",
    "RPAREN",

    "QUOTE",

    "BSLASH",

    "LBRAC",
    "RBRAC",

    "NEWLINE",
    "EOF"
};

typedef struct {
    TokType type;
    char* name;
} Token;

typedef enum {
    AST_NONE,

    AST_ROOT,

    AST_PREPROC_LIB,
    AST_PREPROC_IMP,

    AST_FUNC_DEF,
    AST_FUNC_DEF_PARAMS,
    AST_FUNC_CALL,

    AST_VAR_DEF,

    AST_SCOPE,
    AST_GROUPING,

    AST_STRING,

    AST_NAMESPACE,

    AST_NAME,
    AST_TYPE
} ASTtype;

const char* astTypeNames[] = {
    "WHATTHEFUCK",

    "ROOT",

    "PREPROC-LIB",
    "PREPROC-IMP",

    "FUNC DEF",
    "FUNC DEF - PARAMS",
    "FUNC CALL",

    "VAR DEF",

    "SCOPE",
    "GROUPING",

    "STRING",

    "NAMESPACE",

    "NAME",
    "TYPE"
};

typedef struct {
    ASTtype type;
    Vec children;
    char* val;
} ASTnode;

typedef struct {
    char* buf;
    size_t len;
    size_t cap;
} StringBuilder;

void sb_init(StringBuilder* sb) {
    sb->len = 0;
    sb->cap = 64;
    sb->buf = malloc(sb->cap);
    sb->buf[0] = '\0';
}

void sb_append(StringBuilder* sb, const char* str) {
    size_t slen = strlen(str);
    if (sb->len + slen + 1 > sb->cap) {
        sb->cap = (sb->len + slen + 1) * 2;
        sb->buf = realloc(sb->buf, sb->cap);
    }
    memcpy(sb->buf + sb->len, str, slen + 1); // +1 for null terminator
    sb->len += slen;
}

void sb_free(StringBuilder* sb) {
    free(sb->buf);
}

Vec toks;

void lex(char* buffer) {
    for (s32 i = 0; buffer[i] != '\0'; ++i) {
        // if your file isnt like ascii or something then idgaf
        u32 it = 0;
        StringBuilder name;
        while ((buffer[i] >= 'A' && buffer[i] <= 'Z') || (buffer[i] >= 'a' && buffer[i] <= 'z')) {
            if (it == 0) {
                sb_init(&name);
                ++it; 
            } sb_append(&name, (char[2]){ buffer[i++], 0 });
        }
        if (it != 0) {
            Token* tok = malloc(sizeof(Token));
            tok->name = name.buf;
            tok->type = PAR_NAME;
            vec_push(&toks, tok);
        }

        Token* tok = malloc(sizeof(Token));

        switch (buffer[i]) {
#define easy(t, letter) \
    case letter: \
    tok->type = PAR_##t; \
    tok->name = #letter; \
    break

            easy(HASH, '#');
            easy(LESS, '<');
            easy(GREAT, '>');
            easy(COLON, ':');
            easy(LPAREN, '(');
            easy(RPAREN, ')');
            easy(QUOTE, '"');
            easy(LBRAC, '{');
            easy(RBRAC, '}');
            easy(SEMI, ';');
            easy(BSLASH, '\\');
            easy(NEWLINE, '\n');
            easy(EOF, '\0'); // not sure if this will even happen

            default:
                tok->type = PAR_NONE;
                break;
        }

        if (tok->type != PAR_NONE)
            vec_push(&toks, tok);
        else
            free(tok);
    }
}

char* openfile(const char* path) {
    FILE* file = fopen(path, "rb");
    ERROR_IF(!file, "failed to open source at \"%s\"!\n", path);

    fseek(file, 0, SEEK_END);
    s64 size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(size + 1);
    ERROR_IF(!buffer, "failed to alloc size for source at \"%s\"", path);

    fread(buffer, 1, size, file);
    fclose(file);

    buffer[size] = '\0';

    return buffer;
}

typedef struct {
    Vec* toks;
    s32 pos;
} Parser;

Token* cur(Parser* p) { return vec_get(p->toks, p->pos); }
Token* next(Parser* p) { return vec_get(p->toks, ++p->pos); }
Token* at_off(Parser* p, s32 off) { return vec_get(p->toks, p->pos + off); }
b8 at_end(Parser* p) { return p->pos >= (s32)p->toks->len; }

b8 match(Parser* p, TokType type) {
    if (cur(p)->type == type) { next(p); return 1; }
    return 0;
}

void expect(Parser* p, TokType type, const char* msg) {
    if (cur(p)->type != type) {
        printf("type check error! [%s, %s] (%d/%d)\n", tokTypeNames[cur(p)->type], cur(p)->name, p->pos, (s32)p->toks->len);
        ERROR_IF(1, msg);
    }
}

void expect_name(Parser* p, const char* name, const char* msg) {
    if (strcmp(cur(p)->name, name)) {
        printf("name check error!\n [%s, %s] (%d/%d)\n", tokTypeNames[cur(p)->type], cur(p)->name, p->pos, (s32)p->toks->len);
        ERROR_IF(1, msg);
    }
}


ASTnode* make_node(ASTtype type, char* val) {
    ASTnode* n = malloc(sizeof(ASTnode));
    n->type = type;
    n->val = val;
    n->children = vec_new();
    return n;
}

ASTnode* parse_expression(Parser* p);
ASTnode* parse_group(Parser* p);
ASTnode* parse_scope(Parser* p);
ASTnode* parse_function(Parser* p);
ASTnode* parse_namespace(Parser* p);

ASTnode* parse_preproc_LIB(Parser* p);
ASTnode* parse_preproc_IMP(Parser* p);
ASTnode* parse_preproc(Parser* p);

ASTnode* parse_statement(Parser* p) {
    Token* t = cur(p);
    
    if (t->type == PAR_NAME) {
        Token* name = t;
        next(p);

        if (cur(p)->type == PAR_NAME) {
            Token* type = cur(p);
            next(p);
            ASTnode* var = make_node(AST_VAR_DEF, "vardef");

            vec_push(&var->children, make_node(AST_NAME, name->name));
            vec_push(&var->children, make_node(AST_TYPE, type->name));

            if (match(p, PAR_SEMI)) return var;
            if (match(p, PAR_NEWLINE)) return var;
        }

        if (cur(p)->type == PAR_LPAREN) {
            --p->pos;
            return parse_function(p);
        }
    }

    if (t->type == PAR_LBRAC)
        return parse_scope(p);

    if (t->type == PAR_NUM || t->type == PAR_LPAREN)
        return parse_expression(p);

    if (t->type == PAR_HASH)
        return parse_preproc(p);

    if (t->type == PAR_SEMI || t->type == PAR_NEWLINE) {
        next(p);
        return parse_statement(p);
    }

    ERROR_IF(1, "unexpected token in statement!\n");
    return NULL;
}

ASTnode* parse_function(Parser* p) {
    Token* name = cur(p);
    expect(p, PAR_NAME, "part 1/4 of function is not of type PAR_NAME!\n");

    next(p);

    Token* type = cur(p);
    expect(p, PAR_NAME, "part 2/4 of function is not of type PAR_NAME!\n");

    next(p);

    ASTnode* params = parse_group(p);
    next(p);

    ASTnode* scope = parse_scope(p);
    next(p);

    ASTnode* def = make_node(AST_FUNC_DEF, "funcdef");
    vec_push(&def->children, make_node(AST_NAME, name->name));
    vec_push(&def->children, make_node(AST_TYPE, type->name));
    vec_push(&def->children, params);
    vec_push(&def->children, scope);

    return def;
}

ASTnode* parse_expression(Parser* p) { return NULL; }
ASTnode* parse_group(Parser* p) { return NULL; }
ASTnode* parse_scope(Parser* p) { return NULL; }

ASTnode* parse_namespace(Parser* p) {
    ASTnode* ns = make_node(AST_NAMESPACE, "namespace");

    while (!at_end(p)) {
        if (cur(p)->type != PAR_NAME)
            break;

        vec_push(&ns->children, make_node(AST_NAME, cur(p)->name));
        next(p);

        if (cur(p)->type == PAR_COLON) {
            next(p);
            expect(p, PAR_COLON, "parsing namespace, found non ':' char after ':'!\n");
            next(p);
            expect(p, PAR_NAME, "parsing namespace, found token not of type PAR_NAME after '::'!\n");
            continue;
        }

        break;
    }

    --p->pos;
    return ns;
}

ASTnode* parse_preproc_LIB(Parser* p) {
    expect(p, PAR_HASH, "why is the first character of a preproc (lib) not a hash? what the fuck do you expect?\n");
    next(p);

    expect(p, PAR_NAME, "part of preproc (lib) after hash is not of type PAR_NAME!\n");
    expect_name(p, "lib", "part of preproc (lib) after hash is not of name \"lib\"!\n");
    next(p);

    expect(p, PAR_LESS, "part of preproc (lib) after \"lib\" is not of type PAR_LESS!\n");
    next(p);

    ASTnode* ns = parse_namespace(p);
    next(p);

    expect(p, PAR_GREAT, "part of preproc (lib) after namespace is not of type PAR_GREAT!\n");

    ASTnode* lib = make_node(AST_PREPROC_LIB, "lib");
    for (s32 i = 0; i < (s32)ns->children.len; ++i)
        vec_push(&lib->children, vec_get(&ns->children, i));

    return lib;
}

ASTnode* parse_preproc_IMP(Parser* p) {
    expect(p, PAR_HASH, "why is the first character of a preproc (imp) not a hash? what the fuck do you expect?\n");
    next(p);

    expect(p, PAR_NAME, "part of preproc (imp) after hash is not of type PAR_NAME!\n");
    expect_name(p, "imp", "part of preproc (imp) after hash is not of name \"imp\"!\n");
    next(p);

    expect(p, PAR_LESS, "part of preproc (imp) after \"imp\" is not of type PAR_LESS!\n");
    next(p);

    ASTnode* ns = parse_namespace(p);
    next(p);

    expect(p, PAR_GREAT, "part of preproc (imp) after namespace is not of type PAR_GREAT!\n");

    ASTnode* imp = make_node(AST_PREPROC_IMP, "imp");
    for (s32 i = 0; i < (s32)ns->children.len; ++i)
        vec_push(&imp->children, vec_get(&ns->children, i));

    return imp;
}

ASTnode* parse_preproc(Parser* p) {
    expect(p, PAR_HASH, "why is the first character of a preproc not a hash? what the fuck do you expect?\n");
    next(p);

    Token* name = cur(p);
    expect(p, PAR_NAME, "part of preproc after hash is not of type PAR_NAME!\n");

    if (!strcmp(name->name, "lib")) {
        --p->pos;
        return parse_preproc_LIB(p);
    } else if (!strcmp(name->name, "imp")) {
        --p->pos;
        return parse_preproc_IMP(p);
    }

    ERROR_IF(1, "unexpected preprocessor name \"%s\"!\n", name->name);
    return NULL;
}

ASTnode* parse_main(Parser* p) {
    ASTnode* root = make_node(AST_ROOT, "root");
    while (!at_end(p)) {
        ASTnode* st = parse_statement(p);
        if (st) vec_push(&root->children, st);
    }
    return root;
}



void print_ast(ASTnode* ast, s32 indent) {
    printf("%*s[%s, %s]\n", indent*2,"", astTypeNames[ast->type], ast->val);
    if (ast->children.data != NULL)
        for (s32 i = 0; i < (s32)ast->children.len; ++i)
            print_ast(vec_get(&ast->children, i), indent+1);
}

int main(int argc, char** argv) {
    (void)argc;
    const char* path = argv[1];

    char* buffer = openfile(path);
    printf("%s\n", buffer);

    toks = vec_new();

    lex(buffer);

    for (s32 i = 0; i < (s32)toks.len; ++i) {
        Token* tok = vec_get(&toks, i);
        printf("%d: [%s, %s]\n", i, tokTypeNames[tok->type], tok->name);
    }

    printf("\n");
ASTnode* parse_scope(Parser* p);
ASTnode* parse_function(Parser* p);

    Parser* p = malloc(sizeof(Parser));
    p->toks = &toks;
    p->pos = 0;

    ASTnode* ast = parse_main(p);
    ast->type = AST_ROOT;
    ast->val = "root";

    print_ast(ast, 0);

    printf("printed!\n");

    for (s32 i = 0; i < (s32)toks.len; ++i) {
        Token* tok = vec_get(&toks, i);
        if (tok->type == PAR_NAME || tok->type == PAR_NUM)
            free(tok->name);
        if (i != 0)
            free(vec_get(&toks,i));
    }

    vec_free(&toks);

	return 0;
}
