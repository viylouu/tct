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

    AST_FUNC_DEF,
    AST_FUNC_CALL,

    AST_SCOPE,

    AST_STRING,

    AST_NAME
} ASTtype;

const char* astTypeNames[] = {
    "WHATTHEFUCK",

    "ROOT",

    "PREPROC-LIB",

    "FUNC DEF",
    "FUNC CALL",

    "SCOPE",

    "STRING",

    "NAME"
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
    ERROR_IF(!file, "failed to open shader part at \"%s\"!\n", path);

    fseek(file, 0, SEEK_END);
    s64 size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(size + 1);
    ERROR_IF(!buffer, "failed to alloc size for shader part at \"%s\"", path);

    fread(buffer, 1, size, file);
    fclose(file);

    buffer[size] = '\0';

    return buffer;
}

#define new \
    (tok = vec_get(intoks, ++i))
#define get \
    (tok = vec_get(intoks, i))

s32 parse_namespace(Vec* ns, Vec* intoks, s32 i) {
    Token* tok = NULL;
    while(new->type != PAR_GREAT) {
        if (get->type != PAR_COLON)
            vec_push(ns, get->name);
    }
    return i;
}

ASTnode* parse(Vec* intoks, s32 i) {
    Vec nodes = vec_new();
    ASTnode* node = malloc(sizeof(ASTnode));

    while (i < (s32)intoks->len) {
        s32 j = i;
        Token* tok = vec_get(intoks, i);
        if (tok->type == PAR_HASH) {
            if (!strcmp(new->name, "lib")) {
                Vec ns = vec_new();
                i = parse_namespace(&ns, intoks, i+1);
                ASTnode* n = malloc(sizeof(ASTnode));
                n->children = vec_new();
                n->type = AST_PREPROC_LIB;
                n->val = "lib";
                for (s32 j = 0; j < (s32)ns.len; ++j) {
                    ASTnode* a = malloc(sizeof(ASTnode));
                    a->children = vec_new(); // dont free ts
                    a->type = AST_NAME;
                    a->val = vec_get(&ns, j);
                    vec_push(&n->children, a);
                }
                vec_push(&nodes, n);
            }
        }

        if (j == i)
            ++i;
    }

    node->children = nodes;
    return node;
}

void print_ast(ASTnode* ast, s32 indent) {
    printf("%*s[%s, %s]\n", indent*2,"", astTypeNames[ast->type], ast->val);
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
        printf("[%s, %s]\n", tokTypeNames[tok->type], tok->name);
    }

    printf("\n");

    ASTnode* ast = parse(&toks, 0);
    ast->type = AST_ROOT;
    ast->val = "root";

    print_ast(ast, 0);

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
