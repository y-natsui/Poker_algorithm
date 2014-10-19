#include <stdio.h>

int checkError(int card[5]){
  int i,t;

  //エラーチェック
  t=0;
  for (i=0; i<5; i++){

    //「1〜13」より範囲外の数字を除外
    if (card[i]<1 || card[i]>13 ){
      printf("\n1〜13の間で数字を入力して下さい\n\n");
      return 1;
    }

    //同じ数字のカードが５枚存在する場合を除外
    if (i<4 && card[i] == card[i+1]){
      t++;
      if (t==4){
          printf("\n同じ数字のカードは5枚存在しません！\n\n");
          return 1;
      }
    }
  }
  return 0;

}

int score(int card[5]){

  int tmp;
  int p,q;

  //配列の中身を昇順にソート
  for (p=0; p<4; p++){
    for (q=p+1; q<5; q++){

      if (card[p] > card[q]){
        tmp = card[q];
        card[q] = card[p];
        card[p] = tmp;
      }
    }
  }

  printf("\n");
  //入力値表示確認用
  for (int i=0; i<5; i++){
      printf("%d ",card[i]);
  }
  printf("\n");


  int r=0;
  for (p=0; p<4; p++){
    for (q=p+1; q<5; q++){

      if (card[p] == card[q]){
        r++;

      }
    }
  }
  switch (r){
    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        r = r+1;
        break;

    case 6:
        break;

    case 0:
        //「1〜13」を循環するとき
        if (card[4]==13 && card[0]==1){
          int t=0;
          for (p=0; p<4; p++){
            for (q=p+1; q<5; q++){

              if (card[q]-card[p]==1){
                t++;
              }
            }
          }

          if (t==3){
              r = 4;
              break;
            //printf("ストレートです！\n\n");

          } else if (t!=3){
              //printf("役がありません！\n\n");
              r = 0;
              break;
          }

        }

        int u=0;
        for (int i=0; i<4; i++){
          if (card[i+1]-card[i]==1){
            u++;
          }
        }
        //「1〜13」の間の連番のとき
        if (u==4){
          //printf("ストレートです！\n\n");
          r = 4;
          break;

        } else if (u!=4){
          //printf("役がありません！\n");
          r = 0;
          break;
        }

      }

  return r;
}

int main(){
  //こちらにカードの手を入力して下さい
  int card[5] = {11,10,11,10,10};

  //エラーチェック
  int error = checkError(card);
  if (error==1){
    return 0;
  }


  int s = score(card);

  switch (s){
    case 1:
        printf("１ペアです！\n\n");
        break;

    case 2:
        printf("2ペアです！\n\n");
        break;

    case 3:
        printf("3カードです！\n\n");
        break;

    case 4:
        printf("ストレートです！\n\n");
        break;

    case 5:
        printf("フルハウスです！\n\n");
        break;

    case 6:
        printf("4カードです！\n\n");
        break;

    case 0:
        printf("役がありません！\n\n");
        break;

    default:
        return 0;
        break;


  }

}
