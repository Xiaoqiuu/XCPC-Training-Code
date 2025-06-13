public class Person{
    String name;
    int age = 0;
    char gender;
    double height;

    public Person{
        Super();
    }
    public Person(String name, int age, char gender, double height){
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.height = height;
    }
    void speak(String S) {
        System.out.println(S);
    }
}