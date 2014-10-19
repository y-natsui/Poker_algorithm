#include <stdio.h>

int main(){
  //こちらにカードの手を入力して下さい
  int card[5] = {1,1,2,2,2};

  int tmp;
  int i,p,q,t;

  //エラーチェック
  t=0;
  for (i=0; i<5; i++){

    //「1〜13」より範囲外の数字を除外
    if (card[i]<1 || card[i]>13 ){
      printf("\n1〜13の間で数字を入力して下さい\n\n");
      return 0;
    }

    //同じ数字のカードが５枚存在する場合を除外
    if (card[i] == card[i+1]){
      t++;
      if (t==4){
          printf("\n同じ数字のカードは5枚存在しません！\n\n");
          return 0;
      }
    }
  }



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

  if (r==1){
    printf("１ペアです！\n\n");

  } else if (r==2){
    printf("2ペアです！\n\n");

  } else if (r==3){
    printf("3カードです！\n\n");

  } else if (r==4){
    printf("フルハウスです！\n\n");

  } else if (r==6){
    printf("4カードです！\n\n");

  } else if (r==0){

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
        printf("ストレートです！\n\n");

      } else if (t!=3){
          printf("役がありません！\n\n");
          return 0;
      }

    }

    int s=0;
    for (int i=0; i<4; i++){
      if (card[i+1]-card[i]==1){
        s++;
      }
    }
    //「1〜13」の間の連番のとき
    if (s==4){
      printf("ストレートです！\n\n");

    } else if (s!=4){
      //printf("役がありません！\n");
      return 0;
    }

  }


}
