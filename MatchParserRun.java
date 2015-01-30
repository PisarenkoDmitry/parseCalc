/**
 * Created by Дима on 30.01.2015.
 */

import matchParser.MatchParser;



public class MatchParserRun {

    public static void main(String[] args) {
        String[] formulas = new String[] { "2--2","ln(5)","4+3*ln(2)", "3.5.6-2"};
        MatchParser p = new MatchParser();
        for( int i = 0; i < formulas.length; i++){
            try{
                System.out.println( formulas[i] + "=" + p.Parse( formulas[i] ) );
            }catch(Exception e){
                System.err.println( "Error while parsing '"+formulas[i]+"' with message: " + e.getMessage() );
            }
        }

    }

}
