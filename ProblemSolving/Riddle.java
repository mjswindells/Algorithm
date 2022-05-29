// https://udel.edu/~os/riddle.html
// 아인슈타인퍼즐

// enum으로 Color, Nation, Beverage, Cigar, Pet 생성
enum Color{
    Red(0),Green(1),White(2),Yellow(3),Blue(4);
    // 각각의 정보를 index화 시키기 위해 ord 설정
    public int ord = 0;
    Color(int a){
        this.ord=a;
    }
    // ord를 가지고 enum을 get하기 위한 함수
    public static Color byO(int a){
        for(Color m : Color.values())
            if(m.ord == a) return m; 
        return null;
    }
}
enum Nation{
    Brit(0),Dane(1),German(2),Norwegian(3),Swede(4);
    public int ord = 0;
    Nation(int a){
        this.ord=a;
    }
    public static Nation byO(int a){
        for(Nation m : Nation.values())
            if(m.ord == a) return m; 
        return null;
    }
}
enum Beverage{
    Beer(0),Coffe(1),Milk(2),Tea(3),Water(4);
    public int ord = 0;
    Beverage(int a){
        this.ord=a;
    }
    public static Beverage byO(int a){
        for(Beverage m : Beverage.values())
            if(m.ord == a) return m; 
        return null;
    }
}
enum Cigar{
    BlueMaster(0),Dunhill(1),PallMall(2),Prince(3),Blend(4);
    public int ord = 0;
    Cigar(int a){
        this.ord=a;
    }
    public static Cigar byO(int a){
        for(Cigar m : Cigar.values())
            if(m.ord == a) return m; 
        return null;
    }
}
enum Pet{
    Cat(0),Bird(1),Dog(2),Fish(3),Horse(4);
    public int ord = 0;
    Pet(int a){
        this.ord=a;
    }
    public static Pet byO(int a){
        for(Pet m : Pet.values())
            if(m.ord == a) return m; 
        return null;
    }
}
// 각 사람이 가지는 5가지 특성을 가지는 class
class _Person{
    public Nation n;
    public Color c;
    public Beverage b;
    public Cigar ci;
    public Pet p;
    public _Person(){
        n=null;
        c=null;
        b=null;
        ci=null;
        p=null;
    }
}

// Einstein's riddle를 풀기위한 class
public class Riddle{
    // person : 총 5명을 담은 배열
    static _Person[] person = new _Person[5];

    // 5!순열을 전부 담을 배열
    static int plist[][]=new int[120][5];

    // 밑에 3개 변수는 순열을 만들기 위한 변수들
    // list에는 0~4까지의 숫자가 들어간다
    static int list[]=new int[5];
    // 숫자가 선택됐는지 확인하는 boolean형 배열
    static boolean[] selected=new boolean[5];
    // plist의 행을 나타내기 위한 변수
    static int idx=0;

    // plist 에 순열 모든 경우 담는 함수
    // 재귀를 활용하였다.
    private static void permutation(int n){
        if(n==5) {
            for(int i=0;i<5;i++){
                plist[idx][i]=list[i];
            }
            idx++;
            return;
        }
        for(int i=0;i<5;i++){
            if(selected[i]) continue;
            list[n]=i;
            selected[i]=true;
            permutation(n+1);
            selected[i]=false;
        }
    }

    static void Solve(){
        // 총 노드의 갯수를 확인하기 위한 변수
        int count=0;
        // 가능한 모든 경우의수로 Nation을 설정한다.
        for(int N=0;N<120;N++){
            for(int i=0;i<5;i++)
                person[i].n=Nation.byO(plist[N][i]);
            count++;
            if(!Promising(person,0)) continue;
            for(int B=0;B<120;B++){
                for(int i=0;i<5;i++)
                    person[i].b=Beverage.byO(plist[B][i]);
                count++;
                if(!Promising(person,1)) continue;
                for(int C=0;C<120;C++){
                    for(int i=0;i<5;i++)
                        person[i].c=Color.byO(plist[C][i]);
                    count++;
                    if(!Promising(person,2)) continue;
                    for(int CI=0;CI<120;CI++){
                        for(int i=0;i<5;i++)
                            person[i].ci=Cigar.byO(plist[CI][i]);
                        count++;
                        if(!Promising(person,3)) continue;
                        for(int P=0;P<120;P++){
                            for(int i=0;i<5;i++)
                                person[i].p=Pet.byO(plist[P][i]);
                            count++;
                            if(!Promising(person,4)) continue;
                            else{
                                Print(person);
                                System.out.println("총 노드의 갯수 : "+count);
                            }
                        }
                    }
                }

            }
        }
    }
    // mkTable : permu(사람들 배열) teble(permu를 이용해 index화 시킨 배열) item(아이템넘버)
    // 각 enum에 ord를 사용하기 위해 table배열을 만들었다.
    // 예를 들어 permu의 color가 [1, 3, 4 ,2 ,0]인 경우
    //          table은 [4, 0, 3, 1, 2 ]가 된다
    // talbe을 활용해 enum의 item을 가지고 있는 사람을 쉽게 찾을 수 있다.
    public static void mkTable(_Person[] permu, int[] table, int item){
        if(item == 0)
            for(int i=0; i<5; i++)
                table[permu[i].n.ord] = i;
        if(item == 1)
            for(int i=0; i<5; i++)
                table[permu[i].b.ord] = i;
        if(item == 2)
            for(int i=0; i<5; i++)
                table[permu[i].c.ord] = i;
        if(item == 3)
            for(int i=0; i<5; i++)
                table[permu[i].ci.ord] = i;
        if(item == 4)
            for(int i=0; i<5; i++)
                table[permu[i].p.ord] = i;
    }
    // 이웃인지 확인하기 위한 함수
    // me(몇번째 사람인지 idx로 넘긴다) item(아이템넘버 즉, Color인지 Nation인지 등)
    // neigh(item에서 몇번째 value인지)
    // ex) item이 0인 경우만 보면 자신의 인덱스가 0과4 사이에 있어야지 이웃이 가능하다.
    //      그리고 item으로 분류한 enum에서 전과 후과 neigh와 같은지 확인하여 retun한다.
    public static boolean neighbour(int me, _Person[] people,int neigh,int item){
        if(item == 0){
            return ((me > 0) && people[me-1].n == Nation.byO(neigh))
                || ((me < 4) && people[me+1].n == Nation.byO(neigh));
        }
        if(item == 1)
            return ((me > 0) && people[me-1].b == Beverage.byO(neigh))
                || ((me < 4) && people[me+1].b == Beverage.byO(neigh));
        if(item == 2)
            return ((me > 0) && people[me-1].c == Color.byO(neigh))
                || ((me < 4) && people[me+1].c == Color.byO(neigh));
        if(item == 3)
            return ((me > 0) && people[me-1].ci == Cigar.byO(neigh))
                || ((me < 4) && people[me+1].ci == Cigar.byO(neigh));
        else
            return ((me > 0) && people[me-1].p == Pet.byO(neigh))
                || ((me < 4) && people[me+1].p == Pet.byO(neigh));
    }
    // item으로 몇번째 깊이에서 Hint를 사용하여 유요한 경우인지 확인한다.
    public static boolean Promising(_Person[] people, int item){
        int nlist[] = new int[5];   
        int clist[] = new int[5];   
        int cilist[] = new int[5];  
        int plist[] = new int [5];  
        mkTable(people, nlist, 0);
        if( item >= 2 ){
            mkTable(people, clist, 2);
            if( item >= 3){
                mkTable(people, cilist, 3);
                if( item == 4 )
                    mkTable(people, plist, 4);
            }
        }

        if( item == 0 ){
            // Hint 9 : The Norwegian lives in the first(leftmost) house.
            return people[0].n == Nation.Norwegian;
        }
        if( item == 1 ){
            // Hint 8 : The man living in the house right in the center drinks milk
            return (people[2].b == Beverage.Milk)
            // Hint 3 : The Dane drinks tea.
            // Nation의 1번이 Dane이다.
                    && people[nlist[1]].b == Beverage.Tea;
        }
        if( item == 2 ){
            // Hint 1 : The Brit lives in a red house.
            // Nation의 0번이 Brit이다.
            return (people[nlist[0]].c == Color.Red)
            // Hint 5 : The green house owner drinks coffee.
            // Color의 1번이 green이다.
                && (people[clist[1]].b == Beverage.Coffe)
            // Hint 4 : The green house is on the left of the white house
            // 초록색집은 5번째 집 전에 위치해야 한다.
                && (clist[1]<4 && people[clist[1]+1].c == Color.White)
            // Hint 14 :  The Norwegian lives next to the blue house.
            // nlist[3] : 노르웨이사는 집 번호
            // 4 : Color에서 blue는 4번 
            // 2 : neighbour함수에서 색,나라,담배 등 분류 넘버
                && neighbour(nlist[3], people, 4, 2);
        }
        if( item == 3 ){
            // Hint 13 : The German smokes Prince
            // Nation에서 독일 번호는 2
            return (person[nlist[2]].ci == Cigar.Prince)
            // Hint 7 : The owner of the yellow house smokes Dunhill
            // Color에서 노란색은 3번
                && (person[clist[3]].ci ==  Cigar.Dunhill)
            // Hint 12 : The owner who smokes Blue Master drinks beer.
            // Cigar에서 Blue Master의 번호는 0번
                && (people[cilist[0]].b == Beverage.Beer);
        }
        else{
            // Hint 2 : The Swede keeps dogs as pets.
            // Nation에서 swede는 4번
            return (people[nlist[4]].p == Pet.Dog)
            // Hint 6 : The person who smokes Pall Mall rears birds
            // Cigar에서 pallmall의 번호는 2번
                && (person[cilist[2]].p == Pet.Bird)
            // Hint 10 : The man who smokes Blend lives next to the one who keeps cats.
            // cigar에서 Blend의 번호는 4번
            // Pet에서 cat의 번호는 0번 , Pet의 분류번호는 4번
                && neighbour(cilist[4], people, 0, 4)
            // Hint 11 : The man who keeps horses lives next to the man who smokes Dunhill.
            // Pet에서 horse는 4번,     Cigar에서 Dunhill의 번호는 1번,     담배의 분류번호는 3번
                && neighbour(plist[4], people, 1, 3)
            // Hint 15 : The man who smokes Blend has a neighbor who drinks water.
            // Cigar에서 Blend의 번호는 4번,    Beverage에서 water의 번호는 4번 음료의 분류번호는 1번
                && neighbour(cilist[4], people, 4, 1);
        }
    } 
    public static void Print(_Person[] a){
        for(int i=1; i<6; i++){
            System.out.println("House "+i+" : "+a[i-1].c+" "+a[i-1].n+" "+a[i-1].b+" "+a[i-1].ci+" "+a[i-1].p);
        }
    }
    public static void main(String[] args){
        for(int i=0; i<5; i++)
            person[i] = new _Person();
        permutation(0);
        Solve();
    }
}
