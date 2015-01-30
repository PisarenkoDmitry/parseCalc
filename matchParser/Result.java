package matchParser;

/**
 * Created by Дима on 30.01.2015.
 */
class Result
{

    public double acc; // Аккамулятор
    public String rest; // остаток строки, которую мы еще не обработали

    public Result(double v, String r) {
        this.acc = v;
        this.rest = r;
    }
}
