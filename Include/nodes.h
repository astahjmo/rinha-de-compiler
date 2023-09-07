#include <stdint.h>
#include <stdbool.h>

#define Node_HEAD \
    Loc location;

typedef struct
{
    uint64_t start;
    uint64_t end;
    char *filename;
} Loc;

typedef struct
{
    Node_HEAD;
} Node;

typedef struct
{
    Node_HEAD;
    char *name;
    Node *expr;
} File;

typedef struct
{
    Node_HEAD;
    char *kind;
    Node *test;
    Node *then;
    Node *alter;
} If;

typedef struct {
    Node_HEAD;
    char *kind;
    Parameter *name;
    Node *value;
    Node *next;
} Let;

typedef struct
{
    Node_HEAD;
    char *kind;
    char *value;
} Str;

typedef struct
{
    Node_HEAD;
    char *kind;
    bool value;
} Bool;

typedef struct
{
    Node_HEAD;
    char *kind;
    int64_t value;
} Number;

typedef struct
{
    Node_HEAD;
    char *text;
} Parameter;

typedef enum {
    Add,
    Sub,
    Mul,
    Div,
    Rem,
    Eq,
    Neq,
    Lt,
    Gt,
    Lte,
    Gte,
    And,
    Or,
} BinOp;

typedef struct
{
    Node_HEAD;
    char *kind;
    BinOp op;
    Node *lhs;
    Node *rhs;
} Binary;

typedef struct
{
    Node_HEAD;
    char *kind;
    Node *callee;
    Node *arguments[];
} Call;


typedef struct
{
    Node_HEAD;
    char *kind;
    Parameter **parameters;
    Node *value;
} Function;

typedef struct
{
    Node_HEAD;
    char *kind;
    Node *value;
} Print;

typedef struct
{
    Node_HEAD;
    char *kind;
    Node *value;
} First;

typedef struct
{
    Node_HEAD;
    char *kind;
    Node *value;
} Second;

typedef struct
{
    Node_HEAD;
    char *kind;
    Node *first;
    Node *second;
} Tuple;

typedef struct
{
    Node_HEAD;
    char *kind;
    char *text;
} Var;
