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
DictNode *DictTableDataAdd(DicTable* table,char* word,int lid,int rid,int cost,char* csv[0],csv[1],csv[2],csv[3],csv[4],csv[5],csv[6],csv[7],csv[8])
{

DictNode* new_node;
int i;
int n = table->node_num; //nはすでに格納された数/配列の格納先

new_node = LinkedListNodeAlloc();
        if (new_node == NULL) { /* 領域確保失敗 */
        exit (0); /* 終了 */
        }


strcpy(new_node->word ,word);
new_node->id[0] = lid;
new_node->id[1] = rid;
new_node->cost = cost;


for (i=0;i<9;i++){
    strcpy(new_node->csv[i],csv[i]);
}


table->nodes[n] = new_node;
table->nodes++;

return new_node;

}



/*----------------*/
/* テーブル作成関数 */
/*----------------*/
DictTable *DictTableMake(char *filename)
{
    int i;
    FILE *fp;
    char *tp;
    DictTable *table;
    char buffer[100];

    char word[20];
    int id[2];
    int cost;
    char csv[9][50];


    /* ファイル有無のチェック */
    if ((fp = fopen(filename, "r")) == NULL) {
	fprintf(stderr, "No Such File : %s\n", filename);
	exit (1);
    }

    table = DictTableAlloc();
    if (table == NULL) { /* 領域確保失敗 */
	exit (0); /* 終了 */
    }

    while(fscanf(fp,buffer,%s)!=EOF){
        i=0;
        tp = strtok( buffer, "," );
        strcpy(word,tp);
        while ( tp != NULL ) {
            tp = strtok( NULL,"," );
                if ( tp != NULL ) {
                    switch (i){
                        case 1:
                            id[0] = atoi(tp);
                            break;
                        case 2:
                            id[1] = atoi(tp);
                            break;
                        case 3:
                            cost = atoi(tp);
                            break;
                        case 4:
                            strcpy(csv[0],tp);
                            break;
                        case 5:
                            strcpy(csv[1],tp);
                            break;
                        case 6:
                            strcpy(csv[2],tp);
                            break;
                        case 7:
                            strcpy(csv[3],tp);
                            break;
                        case 8:
                            strcpy(csv[4],tp);
                            break;
                        case 9:
                            strcpy(csv[5],tp);
                            break;
                        case 10:
                            strcpy(csv[6],tp);
                            break;
                        case 11:
                            strcpy(csv[7],tp);
                            break;
                        case 12:
                            strcpy(csv[8],tp);
                            break;

                    }

                }
        }
        DictTableDataAdd(table,word,id[0],id[1],cost,csv[0],csv[1],csv[2],csv[3],csv[4],csv[5],csv[6],csv[7],csv[8]); 

    }

    fclose(fp);

    return (table);
}



/*------------------*/
/* 表示関数 */
/*------------------*/
void DictTablePrint(DictTable *table)
{
    DictNode *ptr;
    int i;
    int n = table->node_num; //nはすでに格納された数/配列の格納先

    for (i=0;i<n;i++){
        ptr = table->nodes[i];

        printf("word:%s,lid:%d,rid:%d,cost:%d,csv1:%s,csv1:%s,csv2:%s,csv3:%s,csv4:%s,csv5:%s,csv6:%s,csv7:%s,csv8:%s,csv9:%s\n",
            ptr->word,
            ptr->id[0],ptr->id[1],
            ptr->cost,
            ptr->csv[0],ptr->csv[1],ptr->csv[2],ptr->csv[3],ptr->csv[4],ptr->csv[5],ptr->csv[6],ptr->csv[7],ptr->csv[8])

    }
    
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

