#include "MarbleCollectionGame.cpp"

int main( )
{
    MarbleCollectionGame game;
    vector<string> board;
    /*
    board.push_back( "99#99" );
    board.push_back( "U5LUL" );
    board.push_back( "#LU9U" );
    */
    
    string d[19] = {  "6#344UU78U36U#4U25U", 
                      "543U373U186U23UU0L9", 
                      "299864#3879416UU59#", 
                      "#0U651U#2U1456U993U", 
                      "15988U#L06U235#7LL#", 
                      "U59L881064L602L89U5", 
                      "2221040775857#0096U", 
                      "49U544L37032#U32146", 
                      "97UU8U6897106625809", 
                      "#713L#9L49967L#063#", 
                      "5965#U5974817LUL#50", 
                      "U893171LLU903195364", 
                      "94532L#L64#4#7LUU41", 
                      "8#ULU26705849U41522", 
                      "L6U598450L858#U3558", 
                      "70LUU31731U0L062605", 
                      "327L289L440L2295855", 
                      "3100340502L#3U39348", 
                      "#L062UL#1924510U#82"};
    
    FOR( i, 19 )
    {
         board.push_back( d[i] );
    }
    //board.push_back( "99LU9" );
    cout<<"ANSWA: "<<game.collectMarble( board )<<endl;
    cout<<endl<<"DONE"<<endl;
}
