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
    
    return (list);
}


/*------------------------*/
/* 連結リストへのデータ追加関数 */
/*------------------------*/
DictNode *DictTableDataAdd(DictTable *table, int x)
{
    DictNode *ptr; /* 注目するノードへのポインタ */
    DictNode *prev; /* 直前ノードへのポインタ */
    DictNode *new_node;

    ptr = list->head;
    prev = NULL;

    while (ptr) { /* 終端ノードに到達するまでループ */
	if (ptr->data < x) {
	    prev = ptr; /* 直前ノードの更新 */
	    ptr = ptr->next; /* 注目ノードの更新 */
	} else if (ptr->data == x) { /* x は登録済み */
	    return (NULL);
	} else { /* x を注目ノードの直前に追加 */
	    new_node = DictNodeAlloc();
	    if (new_node == NULL) { /* 領域確保失敗 */
		exit (0); /* 終了 */
	    }
	    new_node->data = x;
	    new_node->next = ptr; /* ポインタの付け替え(注目ノードの直前) */
	    if (prev != NULL) { /* 連結リストの先頭以降に追加 */
		prev->next = new_node; /* ポインタの付け替え */
	    } else { /* 連結リストの先頭に追加 */
		list->head = new_node;
	    }
	    list->node_num++; /* ノード総数の更新 */
	    return (new_node);
	}
    }
    /* 終端ノードに到達 */
    /* x を終端に追加 */
    new_node = DictNodeAlloc();
    if (new_node == NULL) { /* 領域確保失敗 */
	exit (0); /* 終了 */
    }
    new_node->data = x;
    new_node->next = NULL; /* new_node は新たな終端ノード */
    if (prev != NULL) { /* list は少なくともひとつのノードを有している */
	prev->next = new_node; /* 更新前の終端ノードの直後が new_node となる */
    } else { /* list は空(ノードがひとつも含まれない) */
	list->head = new_node;
    }
    list->node_num++; /* ノード総数の更新 */
    return (new_node);
}


/*--------------------------*/
/* 連結リストからのデータ削除関数 */
/*--------------------------*/
int DictTableDataDel(DictTable *table, int x)
{
    DictNode *ptr; /* 注目するノードへのポインタ */
    DictNode *prev; /* 直前ノードへのポインタ */

    ptr = list->head;
    prev = NULL;

    while (ptr) { /* 終端ノードに到達するまでループ */
	if (ptr->data < x) {
	    prev = ptr;
	    ptr = ptr->next;
	} else if (ptr->data == x) { /* ptr は削除ノード */
	    if (prev == NULL) { /* ptr は先頭ノード */
		list->head = ptr->next;
	    } else { /* ptr は先頭ノードでない */
		prev->next = ptr->next;
	    }
	    list->node_num--;
	    free(ptr);
	    return (1);
	} else { /* 削除対象ノードはなし */
	    return (0);
	}
    }
    /* 終端ノードに到達 */
    /* 削除対象ノードはなし */
    return (0);
}


/*----------------*/
/* 連結リスト作成関数 */
/*----------------*/
DictTable *DictTableMake(char *filename)
{
    FILE *fp;
    DictTable *table;
    char buffer[MAXBUFFERSIZE];

    /* ファイル有無のチェック */
    if ((fp = fopen(filename, "r")) == NULL) {
	fprintf(stderr, "No Such File : %s\n", filename);
	exit (1);
    }

    list = DictTableAlloc();
    if (list == NULL) { /* 領域確保失敗 */
	exit (0); /* 終了 */
    }

    while (fgets(buffer, MAXBUFFERSIZE, fp)) { /* ファイル終端に到達するまでループ */
	buffer[strlen(buffer) - 1] = '\0'; /* 改行文字を削除 */
	DictTableDataAdd(list, atoi(buffer));
    }
    fclose(fp);

    return (list);
}


/*---------------------*/
/* 連結リストの領域開放関数 */
/*---------------------*/
void DictTableFree(DictTable *table)
{
    DictNode *ptr; /* 注目ノードへのポインタ */
    DictNode *rem; /* 削除ノード */

    ptr = list->head;

    while (ptr) { /* 終端ノードに到達するまでループ */
	rem = ptr;
	ptr = ptr->next;
	free(rem);
    }
    free(list);
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

