global calculate_surface_area_tetra
global calculate_surface_area_sphere
global calculate_surface_area_parallelepiped


SECTION .text                             

calculate_surface_area_tetra:
        push    rbp                                     
        mov     rbp, rsp                                
        vmovsd  qword [rbp-8H], xmm0                    
        vmovsd  xmm0, qword [rbp-8H]                    
        vmulsd  xmm0, xmm0, xmm0                        
        vmovsd  xmm1, qword [rel ?_001]                 
        vmulsd  xmm0, xmm0, xmm1                        
        pop     rbp                                     
        ret                                             


calculate_surface_area_sphere:
        push    rbp                                     
        mov     rbp, rsp                                
        vmovsd  qword [rbp-8H], xmm0                    
        vmovsd  xmm1, qword [rbp-8H]                    
        vmovsd  xmm0, qword [rel ?_002]                 
        vmulsd  xmm0, xmm1, xmm0                        
        vmulsd  xmm0, xmm0, qword [rbp-8H]              
        pop     rbp                                     
        ret                                             


calculate_surface_area_parallelepiped:
        push    rbp                                     
        mov     rbp, rsp                                
        vmovsd  qword [rbp-8H], xmm0                    
        vmovsd  qword [rbp-10H], xmm1                   
        vmovsd  qword [rbp-18H], xmm2                   
        vmovsd  xmm0, qword [rbp-18H]                   
        vmulsd  xmm1, xmm0, xmm0                        
        vmovsd  xmm0, qword [rbp-8H]                    
        vmulsd  xmm0, xmm0, qword [rbp-10H]             
        vaddsd  xmm1, xmm1, xmm0                        
        vmovsd  xmm0, qword [rbp-8H]                    
        vmulsd  xmm0, xmm0, qword [rbp-18H]             
        vaddsd  xmm0, xmm1, xmm0                        
        vaddsd  xmm0, xmm0, xmm0                        
        pop     rbp                                     
        ret                                                                     


SECTION .rodata                         

?_001:                                                  
        dq 3FFBB67AE8584CAAH                            

?_002:  dq 402921FB54442D18H                            

