#include "processor.h"

template <typename T>
Iprocessor<T>::Echo(T buffer[]) {
	int i = 0, delay = 0;	
        for(i;T buffer[i] != '\0'; i++){

		delay = T buffer[i];

                if(i - delay >= 0){
          
                        delay = 0.5*(T buffer[i] + T buffer[i - delay]);
			T buffer[i] = delay;
                };
        };

	return T buffer[];
};

template <typename T>
Iprocessor<T>::NoiseGate(T buffer[]) {
	
	int i = 0, percentU, percentL;

	cout << "Set an upper noise percent limit : ";
	cin >> percentU;
	cout << "Set a lower noise percent limit: ";
	cin >> percentL;

        for(i;T buffer[i] != '\0'; i++){

		if(T buffer[i] >= 255(percentU){
			T buffer[i] = 255(percentU);
		}else if(T buffer[i] <= 255(percentL)){
			T buffer[i] = 255(percentL);
		}else{
			T buffer[i] = T buffer[i]
		};

        };

	return T buffer[];

};



template <typename T>
Iprocessor<T>::Limiter(T buffer[]) {
	 int i = 0, delay = 0;

        for(i;T buffer[i] != '\0'; i++){

		delay = T buffer[i];

                if(delay >= 0.8*255){
                        delay = 229;
                }else if(delay <= 0.2*255){
                        delay = 26;
                };

		T buffer[i] = delay;

        };

	return T buffer[];

};

template <typename T>
Iprocessor<T>::noProcess(T buffer[]) {
	 
	return T buffer[];

};
