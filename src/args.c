#include "header.h"
#include "args.h"


args_t argument = {
	.help = false,
	.port = DNS_PORT_STR,
	.server = "127.0.0.53",
	.choice = DEFAULT_STRATEGY,
	.params = DEFAULT_INIT_LOG
};

void parseArgs(int argc, char *argv[])
{
	int c;

	static struct option long_options[] = 
	{
		{"help", 		no_argument, 		0, 'h'},
		{"port", 		required_argument, 	0, 'p'},
		{"serveur", 	required_argument, 	0, 's'},
		{"logstrategy", 	required_argument, 	0, 'l'},
		{"initlogstrategie", 	required_argument, 	0, 'i'},
		{0, 0, 0, 0}
	};

	while(1)
	{
		int option_index = 0;
		c = getopt_long(argc, argv, "hp:s:l:i:", long_options, &option_index);
		if(c == -1)
			break;

		switch(c)
		{
			case 'h': argument.help = true;
					  break;
			case 'p': if(strlen(optarg)<(MAX_PORT_SIZE-1))
						  strcpy(argument.port, optarg);
					  else
					  {
						  strncpy(argument.port, optarg, MAX_PORT_SIZE-1);
						  argument.port[MAX_PORT_SIZE-1] = '\0';
					  }
					  break;
			case 's' : if(strlen(optarg)<(MAX_SERVICE_SIZE-1))
						  strcpy(argument.server, optarg);
					  else
					  {
						  strncpy(argument.port, optarg, MAX_SERVICE_SIZE-1);
						  argument.server[MAX_SERVICE_SIZE-1] = '\0';
					  }
					  break;
			case 'l' : if(strlen(optarg)<(MAX_CHOICE_SIZE-1))
						  strcpy(argument.choice, optarg);
						  
					  else
					  {
						  strncpy(argument.choice, optarg, MAX_CHOICE_SIZE-1);
						  argument.server[MAX_CHOICE_SIZE-1] = '\0';
					  }
					  //if(loadStrategy(argument.choice) == -1) printf("Loading strategie error\n");
					  break;
			case 'i' : if(strlen(optarg)<(MAX_PARAMS_SIZE-1))
						   strcpy(argument.params, optarg);
					  else
					  {
						  strncpy(argument.params, optarg, MAX_PARAMS_SIZE-1);
						  argument.params[MAX_PARAMS_SIZE-1] = '\0';
					  }
					  break;
		}
	}
}
