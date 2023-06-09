import java.util.Random;

public class FrogJumpProbability {
    public static void main(String[] args) {
        int N = 10000000; // 시뮬레이션 횟수
        int Jumps = 7; // 점프 횟수
        double radius = 3.0; // 성공 원의 반지름

        int count = 0; // 시뮬레이션 성공한 횟수

        Random random = new Random();

        for (int i = 0; i < N; i++) {
            double x = 0.0; // X좌표
            double y = 0.0; // Y좌표
            for (int j = 0; j < Jumps; j++) {
                // 한번 점프할 때 랜덤한 각 생성
                double angle = random.nextDouble() * 2 * Math.PI;
                // 랜덤한 각을 기준으로 좌표 재배치
                x += Math.cos(angle);
                y += Math.sin(angle);
            }
            // 7번 점프 후 반지름이 3 안에 있으면 count증가
            if (Math.sqrt(x * x + y * y) <= radius) {
                count++;
            }
        }
        double probability = (double) count / N;

        System.out.println("시행 횟수 : "+ N);
        System.out.println("확률      : "+ probability);
    }
}
