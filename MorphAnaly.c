/*=======================*/
/* 連結リスト処理のための関数 */
/*=======================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 10000

/*-------*/
/* 構造体 */
/*-------*/
typedef struct 
{
    char word[20];
    int id[2];
    int cost;
    char csv[9][50];

} DictNode;

typedef struct
{
    int node_num;
    DictNode *nodes[10000];
} DictTable;

/*--------------------------*/
/* ノードの領域確保関数 */
/*--------------------------*/
DictNode *DictNodeAlloc(void)
{
    DictNode *node;
    node = (DictNode *)malloc(sizeof(DictNode));
    if (node == NULL) { /* 領域確保失敗 */
	return (NULL);
    }
    

    return (node);
}


/*---------------------*/
/* テーブルの領域確保関数 */
/*---------------------*/
DictTable *DictTableAlloc(void)
{
    DictTable *table;

    table = (DictTable *)malloc(sizeof(DictTable));
    if (table == NULL) { /* 領域確保失敗 */
	return (NULL);
    }
    table->node_num = 0;
    
    return (table);
}


/*------------------------*/
/* データ追加関数 */
/*------------------------*/
DictNode *DictTableDataAdd(DictTable *table, int x)
{
DictNode* new_node;

int n = table->node_num //nはすでに格納された数/配列の格納先

new_node = LinkedListNodeAlloc();
        if (new_node == NULL) { /* 領域確保失敗 */
        exit (0); /* 終了 */
        }


new_node->word = 


table->nodes[n] = new_node;
table->nodes++;

return new_node;

}



/*----------------*/
/* テーブル作成関数 */
/*----------------*/
DictTable *DictTableMake(char *filename)
{
   
    FILE *fp;
    char *tp;
    DictTable *table;
    char buffer[100];

    /* ファイル有無のチェック */
    if ((fp = fopen(filename, "r")) == NULL) {
	fprintf(stderr, "No Such File : %s\n", filename);
	exit (1);
    }

    table = DictTableAlloc();
    if (table == NULL) { /* 領域確保失敗 */
	exit (0); /* 終了 */
    }

    while(fscanf(fp,buffer,%s)!=EOF){}
    tp = strtok( str, "," );
    puts( tp );
    while ( tp != NULL ) {
        tp = strtok( NULL,"," );
            if ( tp != NULL ) puts( tp );
    }

}







    while () { /* ファイル終端に到達するまでループ */
	buffer[strlen(buffer) - 1] = '\0'; /* 改行文字を削除 */
	DictTableDataAdd(list, atoi(buffer));
    }
    fclose(fp);

    return (list);
}



/*------------------*/
/* 連結リストの表示関数 */
/*------------------*/
void DictTablePrint(DictTable *table)
{
    DictNode *ptr;
    
    ptr = list->head;
    printf("[ ");
    while (ptr) {
	printf("%d ", ptr->data);
	ptr = ptr->next;
    }
    printf("]\n");
}

/*------------------*/
/* 連結リストの中身を線形探索 */
/*------------------*/
DictNode *DictTableSearch(DictTable *table,int x)
{
    DictNode *ptr;
    
    ptr = list->head;
    while (ptr) {
      if (ptr->data == x) return ptr;
    ptr = ptr->next;
    }
    return NULL;
}

