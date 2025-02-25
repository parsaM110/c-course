int main(){

    struct AddressIPV4{
        char ip[16]; // 4 * 3 + 3 =>  15 => 16 (last char should be null for str)
        int port ;
    };

    struct AddressIPV6{
        char ip[42]; // 32 + 7 => 41 => 42
         int port ;
    };

    Union Address{
        struct AddressIPV4 v4;
        struct AddressIPV6 v6;
    };

    union Address A;
    A.v4.ip = "192.168.12.13";
    A.v4.port = 80;

   



}