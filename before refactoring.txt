int main(void)
{
    char input_cmd[ENOUGH_SIZE] = {0};
    get_input_cmd(&input_cmd, ENOUGH_SIZE);
    int input_data = get_input_data(input_cmd, strlen(input_cmd));
    int access_right = get_access(); //1 = admin; 0 = user

    if (!strcmp(input_cmd, "A_cmd"))
    {
        if (access_right == admin)
        {
            A_calculate_data_and_save_result_to_buffer(input_data);
            move_all_buffer_to_rom();
            A_show_result();
            
            return 0;
        }
        else
        {
            //error: access deny
            return -1;
        }
    }
    else if (!strcmp(input_cmd, "B_cmd"))
    {
        B_calculate_data_and_save_result_to_buffer(input_data);
        move_all_buffer_to_rom();
        B_show_result();
        
        return 0;
    }
    else if (!strcmp(input_cmd, "C_cmd"))
    {
        C_calculate_data_and_save_result_to_buffer(input_data);
        C_show_result();
        
        return 0;
    }
    else if (!strcmp(input_cmd, "D_cmd"))
    {
        D_calculate_data_and_save_result_to_buffer(input_data);
        
        return 0;
    }
    else if (!strcmp(input_cmd, "E_cmd"))
    {
        E_calculate_data_and_save_result_to_buffer(input_data);
        move_all_buffer_to_rom();
        
        return 0;
    }
    else if (!strcmp(input_cmd, "F_cmd"))
    {
        if (access_right == admin)
        {
            F_calculate_data_and_save_result_to_buffer(input_data);
            move_all_buffer_to_rom();
            
            return 0;
        else
        {
            //error: access deny
            return -1;
        }
    }
    else if (!strcmp(input_cmd, "G_cmd"))
    {
        if (access_right == admin)
        {
            G_calculate_data_and_save_result_to_buffer(input_data);
            
            return 0;
        else
        {
            //error: access deny
            return -1;
        }
    }
    else if (!strcmp(input_cmd, "H_cmd"))
    {
        if (access_right == admin)
        {
            H_calculate_data_and_save_result_to_buffer(input_data);
            H_show_result();
            return 0;
        else
        {
            //error: access deny
            
            return -1;
        }
    }
    else
    {
        //error: cmd not found
        return -2;
    }
    
    return 0;
}
