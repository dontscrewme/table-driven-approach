static bool find_cmd(char* input, uint16_t* index);
static bool check_access(void);
static void do_nothing(void);

typedef struct cmd_t cmd_t;
struct cmd_t
{
    const char* cmd_name;
    bool need_check_access;
    bool need_move_all_buffer_to_rom;
    void (*calculate_data_and_save_result_to_buffer)(int);
    void (*show_result)(void);
};

#define YES 1
#define NO 0

static cmd_t cmd_table[] =  
{
    {"A_cmd", YES, YES, &A_calculate_data_and_save_result_to_buffer, &A_show_result},
    {"B_cmd", NO,  YES, &B_calculate_data_and_save_result_to_buffer, &B_show_result},
    {"C_cmd", NO,  NO,  &C_calculate_data_and_save_result_to_buffer, &C_show_result},
    {"D_cmd", NO,  NO,  &D_calculate_data_and_save_result_to_buffer, &do_nothing},
    {"E_cmd", NO,  YES, &E_calculate_data_and_save_result_to_buffer, &do_nothing},
    {"F_cmd", YES, YES, &F_calculate_data_and_save_result_to_buffer, &do_nothing},
    {"G_cmd", YES, NO,  &G_calculate_data_and_save_result_to_buffer, &do_nothing},
    {"H_cmd", YES, NO,  &H_calculate_data_and_save_result_to_buffer, &H_show_result},
};


int main(void)
{
    char input_cmd[ENOUGH_SIZE] = {0};
    get_input_cmd(&input_cmd, ENOUGH_SIZE);
    
    uint16_t idx = 0;
    bool cmd_found = find_cmd(input_cmd, &idx);
    if (!cmd_found)
    {
        return -2;
    }
    
    if (cmd_table[idx].need_check_access)
    {
        bool access_allowed = check_access();
        if (!access_allowed)
        {
            return -1;
        }
    }
    
    int input_data = get_input_data(input_cmd, strlen(input_cmd));
    cmd_table[idx].calculate_data_and_save_result_to_buffer(input_data);
    
    if (cmd_table[idx].need_move_all_buffer_to_rom)
    {
        move_all_buffer_to_rom();
    }

    cmd_table[idx].show_result();
    
    return 0;
}

static bool find_cmd(char* input, uint16_t* index)
{
    //loop table and compare string to find cmd
}

static bool check_access(void)
{

#define allowed 1
#define denied 0

    bool rv = denied;
    
    int access_right = get_access(); //1 = admin; 0 = user

    if (access_right == admin)
    {
        rv = allowed;
    }

    return rv;
}

static void do_nothing(void)
{
    
}
