Dump of assembler code for function _ZN7Circuit8KCLSolveEv:
113	void Circuit::KCLSolve() {
   0x0000555555559c6a <+0>:	endbr64
   0x0000555555559c6e <+4>:	push   %rbp
   0x0000555555559c6f <+5>:	mov    %rsp,%rbp
   0x0000555555559c72 <+8>:	push   %rbx
   0x0000555555559c73 <+9>:	sub    $0x2c8,%rsp
   0x0000555555559c7a <+16>:	mov    %rdi,-0x2b8(%rbp)
=> 0x0000555555559c81 <+23>:	mov    %fs:0x28,%rax
   0x0000555555559c8a <+32>:	mov    %rax,-0x18(%rbp)
   0x0000555555559c8e <+36>:	xor    %eax,%eax

114	    // Determine number of nodes and voltage sources
115	    int maxNode = -1;
   0x0000555555559c90 <+38>:	movl   $0xffffffff,-0x2a4(%rbp)

116	    int numVoltageSources = 0;
   0x0000555555559c9a <+48>:	movl   $0x0,-0x298(%rbp)

117	    for (Bipole* bipole : bipoles) {
   0x0000555555559ca4 <+58>:	mov    -0x2b8(%rbp),%rax
   0x0000555555559cab <+65>:	mov    %rax,-0x260(%rbp)
   0x0000555555559cb2 <+72>:	mov    -0x260(%rbp),%rax
   0x0000555555559cb9 <+79>:	mov    %rax,%rdi
   0x0000555555559cbc <+82>:	call   0x555555557768 <_ZNSt6vectorIP6BipoleSaIS1_EE5beginEv>
   0x0000555555559cc1 <+87>:	mov    %rax,-0x100(%rbp)
   0x0000555555559cc8 <+94>:	mov    -0x260(%rbp),%rax
   0x0000555555559ccf <+101>:	mov    %rax,%rdi
   0x0000555555559cd2 <+104>:	call   0x5555555577b4 <_ZNSt6vectorIP6BipoleSaIS1_EE3endEv>
   0x0000555555559cd7 <+109>:	mov    %rax,-0xc0(%rbp)
   0x0000555555559cde <+116>:	jmp    0x555555559d97 <_ZN7Circuit8KCLSolveEv+301>
   0x0000555555559ce3 <+121>:	lea    -0x100(%rbp),%rax
   0x0000555555559cea <+128>:	mov    %rax,%rdi
   0x0000555555559ced <+131>:	call   0x555555557868 <_ZNK9__gnu_cxx17__normal_iteratorIPP6BipoleSt6vectorIS2_SaIS2_EEEdeEv>
   0x0000555555559cf2 <+136>:	mov    (%rax),%rax
   0x0000555555559cf5 <+139>:	mov    %rax,-0x238(%rbp)
   0x0000555555559d88 <+286>:	lea    -0x100(%rbp),%rax
   0x0000555555559d8f <+293>:	mov    %rax,%rdi
   0x0000555555559d92 <+296>:	call   0x555555557844 <_ZN9__gnu_cxx17__normal_iteratorIPP6BipoleSt6vectorIS2_SaIS2_EEEppEv>
   0x0000555555559d97 <+301>:	lea    -0xc0(%rbp),%rdx
   0x0000555555559d9e <+308>:	lea    -0x100(%rbp),%rax
   0x0000555555559da5 <+315>:	mov    %rdx,%rsi
   0x0000555555559da8 <+318>:	mov    %rax,%rdi
   0x0000555555559dab <+321>:	call   0x555555557804 <_ZN9__gnu_cxxneIPP6BipoleSt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESC_>
   0x0000555555559db0 <+326>:	test   %al,%al
   0x0000555555559db2 <+328>:	jne    0x555555559ce3 <_ZN7Circuit8KCLSolveEv+121>

118		maxNode = std::max(maxNode, bipole->getNode1());
   0x0000555555559cfc <+146>:	mov    -0x238(%rbp),%rax
   0x0000555555559d03 <+153>:	mov    %rax,%rdi
   0x0000555555559d06 <+156>:	call   0x55555555c86a <_ZNK6Bipole8getNode1Ev>
   0x0000555555559d0b <+161>:	mov    %eax,-0x120(%rbp)
   0x0000555555559d11 <+167>:	lea    -0x120(%rbp),%rdx
   0x0000555555559d18 <+174>:	lea    -0x2a4(%rbp),%rax
   0x0000555555559d1f <+181>:	mov    %rdx,%rsi
   0x0000555555559d22 <+184>:	mov    %rax,%rdi
   0x0000555555559d25 <+187>:	call   0x55555555cb3d <_ZSt3maxIiERKT_S2_S2_>
   0x0000555555559d2a <+192>:	mov    (%rax),%eax
   0x0000555555559d2c <+194>:	mov    %eax,-0x2a4(%rbp)

119		maxNode = std::max(maxNode, bipole->getNode2());
   0x0000555555559d32 <+200>:	mov    -0x238(%rbp),%rax
   0x0000555555559d39 <+207>:	mov    %rax,%rdi
   0x0000555555559d3c <+210>:	call   0x55555555c880 <_ZNK6Bipole8getNode2Ev>
   0x0000555555559d41 <+215>:	mov    %eax,-0x120(%rbp)
   0x0000555555559d47 <+221>:	lea    -0x120(%rbp),%rdx
   0x0000555555559d4e <+228>:	lea    -0x2a4(%rbp),%rax
   0x0000555555559d55 <+235>:	mov    %rdx,%rsi
   0x0000555555559d58 <+238>:	mov    %rax,%rdi
   0x0000555555559d5b <+241>:	call   0x55555555cb3d <_ZSt3maxIiERKT_S2_S2_>
   0x0000555555559d60 <+246>:	mov    (%rax),%eax
   0x0000555555559d62 <+248>:	mov    %eax,-0x2a4(%rbp)

120		if (bipole->getType() == Type::VOLTAGE_SOURCE) {
   0x0000555555559d68 <+254>:	mov    -0x238(%rbp),%rax
   0x0000555555559d6f <+261>:	mov    %rax,%rdi
   0x0000555555559d72 <+264>:	call   0x55555555c896 <_ZNK6Bipole7getTypeEv>
   0x0000555555559d77 <+269>:	cmp    $0x3,%eax
   0x0000555555559d7a <+272>:	sete   %al
   0x0000555555559d7d <+275>:	test   %al,%al
   0x0000555555559d7f <+277>:	je     0x555555559d88 <_ZN7Circuit8KCLSolveEv+286>

121		    numVoltageSources++;
   0x0000555555559d81 <+279>:	addl   $0x1,-0x298(%rbp)

122		}
123	    }
124	    int n = maxNode + 1; // Number of nodes
   0x0000555555559db8 <+334>:	mov    -0x2a4(%rbp),%eax
   0x0000555555559dbe <+340>:	add    $0x1,%eax
   0x0000555555559dc1 <+343>:	mov    %eax,-0x2a0(%rbp)

125	    int refNode = 0;
   0x0000555555559dc7 <+349>:	movl   $0x0,-0x280(%rbp)

126	
127	    int numEdges = bipoles.size();
   0x0000555555559dd1 <+359>:	mov    -0x2b8(%rbp),%rax
   0x0000555555559dd8 <+366>:	mov    %rax,%rdi
   0x0000555555559ddb <+369>:	call   0x55555555804a <_ZNKSt6vectorIP6BipoleSaIS1_EE4sizeEv>
   0x0000555555559de0 <+374>:	mov    %eax,-0x27c(%rbp)

128	
129	    // Build admittance matrix Y (numEdges x numEdges)
130	    Eigen::MatrixXcd Y = Eigen::MatrixXcd::Zero(numEdges, numEdges);
   0x0000555555559de6 <+380>:	mov    -0x27c(%rbp),%eax
   0x0000555555559dec <+386>:	movslq %eax,%rdx
   0x0000555555559def <+389>:	mov    -0x27c(%rbp),%eax
   0x0000555555559df5 <+395>:	movslq %eax,%rcx
   0x0000555555559df8 <+398>:	lea    -0xc0(%rbp),%rax
   0x0000555555559dff <+405>:	mov    %rcx,%rsi
   0x0000555555559e02 <+408>:	mov    %rax,%rdi
   0x0000555555559e05 <+411>:	call   0x55555555ad3a <Eigen::DenseBase<Eigen::Matrix<std::complex<double>, -1, -1, 0, -1, -1> >::Zero(Eigen::Index, Eigen::Index)>
   0x0000555555559e0a <+416>:	lea    -0xc0(%rbp),%rdx
   0x0000555555559e11 <+423>:	lea    -0x1e0(%rbp),%rax
   0x0000555555559e18 <+430>:	mov    %rdx,%rsi
   0x0000555555559e1b <+433>:	mov    %rax,%rdi
   0x0000555555559e1e <+436>:	call   0x55555555cdf6 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEC2INS_14CwiseNullaryOpINS_8internal18scalar_constant_opIS2_EES3_EEEERKNS_9EigenBaseIT_EE>

131	    Eigen::VectorXcd V_S = Eigen::VectorXcd::Zero(numVoltageSources);
   0x0000555555559e23 <+441>:	mov    -0x298(%rbp),%eax
   0x0000555555559e29 <+447>:	movslq %eax,%rdx
   0x0000555555559e2c <+450>:	lea    -0xc0(%rbp),%rax
   0x0000555555559e33 <+457>:	mov    %rdx,%rsi
   0x0000555555559e36 <+460>:	mov    %rax,%rdi
   0x0000555555559e39 <+463>:	call   0x55555555adac <Eigen::DenseBase<Eigen::Matrix<std::complex<double>, -1, 1, 0, -1, 1> >::Zero(Eigen::Index)>
   0x0000555555559e3e <+468>:	lea    -0xc0(%rbp),%rdx
   0x0000555555559e45 <+475>:	lea    -0x230(%rbp),%rax
   0x0000555555559e4c <+482>:	mov    %rdx,%rsi
   0x0000555555559e4f <+485>:	mov    %rax,%rdi
   0x0000555555559e52 <+488>:	call   0x55555555ce6a <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEC2INS_14CwiseNullaryOpINS_8internal18scalar_constant_opIS2_EES3_EEEERKNS_9EigenBaseIT_EE>

132	    int vsIndex = 0;
   0x0000555555559e57 <+493>:	movl   $0x0,-0x294(%rbp)

133	    for (int i = 0; i < numEdges; i++) {
   0x0000555555559e61 <+503>:	movl   $0x0,-0x290(%rbp)
   0x0000555555559e6b <+513>:	jmp    0x555555559fc1 <_ZN7Circuit8KCLSolveEv+855>
   0x0000555555559fba <+848>:	addl   $0x1,-0x290(%rbp)
   0x0000555555559fc1 <+855>:	mov    -0x290(%rbp),%eax
   0x0000555555559fc7 <+861>:	cmp    -0x27c(%rbp),%eax
   0x0000555555559fcd <+867>:	jl     0x555555559e70 <_ZN7Circuit8KCLSolveEv+518>

134		Bipole* bipole = bipoles[i];
   0x0000555555559e70 <+518>:	mov    -0x2b8(%rbp),%rax
   0x0000555555559e77 <+525>:	mov    -0x290(%rbp),%edx
   0x0000555555559e7d <+531>:	movslq %edx,%rdx
   0x0000555555559e80 <+534>:	mov    %rdx,%rsi
   0x0000555555559e83 <+537>:	mov    %rax,%rdi
   0x0000555555559e86 <+540>:	call   0x55555555ced2 <_ZNSt6vectorIP6BipoleSaIS1_EEixEm>
   0x0000555555559e8b <+545>:	mov    (%rax),%rax
   0x0000555555559e8e <+548>:	mov    %rax,-0x240(%rbp)

135		if (bipole->getType() == Type::VOLTAGE_SOURCE) {
   0x0000555555559e95 <+555>:	mov    -0x240(%rbp),%rax
   0x0000555555559e9c <+562>:	mov    %rax,%rdi
   0x0000555555559e9f <+565>:	call   0x55555555c896 <_ZNK6Bipole7getTypeEv>
   0x0000555555559ea4 <+570>:	cmp    $0x3,%eax
   0x0000555555559ea7 <+573>:	sete   %al
   0x0000555555559eaa <+576>:	test   %al,%al
   0x0000555555559eac <+578>:	je     0x555555559f0f <_ZN7Circuit8KCLSolveEv+677>

136		    V_S[vsIndex++] = bipole->getVoltage();
   0x0000555555559eae <+580>:	mov    -0x240(%rbp),%rax
   0x0000555555559eb5 <+587>:	mov    %rax,%rdi
   0x0000555555559eb8 <+590>:	call   0x555555558f38 <_ZNK6Bipole10getVoltageEv>
   0x0000555555559ebd <+595>:	movsd  %xmm0,-0x2c0(%rbp)
   0x0000555555559ec5 <+603>:	movsd  %xmm1,-0x2c8(%rbp)
   0x0000555555559ecd <+611>:	mov    -0x294(%rbp),%eax
   0x0000555555559ed3 <+617>:	lea    0x1(%rax),%edx
   0x0000555555559ed6 <+620>:	mov    %edx,-0x294(%rbp)
   0x0000555555559edc <+626>:	movslq %eax,%rdx
   0x0000555555559edf <+629>:	lea    -0x230(%rbp),%rax
   0x0000555555559ee6 <+636>:	mov    %rdx,%rsi
   0x0000555555559ee9 <+639>:	mov    %rax,%rdi
   0x0000555555559eec <+642>:	call   0x55555555cef6 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELi1EEixEl>
   0x0000555555559ef1 <+647>:	movsd  -0x2c0(%rbp),%xmm2
   0x0000555555559ef9 <+655>:	movsd  %xmm2,(%rax)
   0x0000555555559efd <+659>:	movsd  -0x2c8(%rbp),%xmm3
   0x0000555555559f05 <+667>:	movsd  %xmm3,0x8(%rax)

137		    // Skip setting Y for voltage sources
138		    continue;
   0x0000555555559f0a <+672>:	jmp    0x555555559fba <_ZN7Circuit8KCLSolveEv+848>

139		}
140		Y(i, i) = 1.0 / bipole->getImpedance();
   0x0000555555559f0f <+677>:	mov    -0x240(%rbp),%rax
   0x0000555555559f16 <+684>:	mov    (%rax),%rax
   0x0000555555559f19 <+687>:	add    $0x10,%rax
   0x0000555555559f1d <+691>:	mov    (%rax),%rdx
   0x0000555555559f20 <+694>:	mov    -0x240(%rbp),%rax
   0x0000555555559f27 <+701>:	mov    %rax,%rdi
   0x0000555555559f2a <+704>:	call   *%rdx
   0x0000555555559f2c <+706>:	movq   %xmm0,%rax
   0x0000555555559f31 <+711>:	movapd %xmm1,%xmm0
   0x0000555555559f35 <+715>:	mov    %rax,-0xc0(%rbp)
   0x0000555555559f3c <+722>:	movsd  %xmm0,-0xb8(%rbp)
   0x0000555555559f44 <+730>:	movsd  0xa8294(%rip),%xmm0        # 0x5555556021e0
   0x0000555555559f4c <+738>:	movsd  %xmm0,-0x100(%rbp)
   0x0000555555559f54 <+746>:	lea    -0xc0(%rbp),%rdx
   0x0000555555559f5b <+753>:	lea    -0x100(%rbp),%rax
   0x0000555555559f62 <+760>:	mov    %rdx,%rsi
   0x0000555555559f65 <+763>:	mov    %rax,%rdi
   0x0000555555559f68 <+766>:	call   0x55555555cfeb <_ZStdvIdESt7complexIT_ERKS1_RKS2_>
   0x0000555555559f6d <+771>:	movsd  %xmm0,-0x2c0(%rbp)
   0x0000555555559f75 <+779>:	movsd  %xmm1,-0x2c8(%rbp)
   0x0000555555559f7d <+787>:	mov    -0x290(%rbp),%eax
   0x0000555555559f83 <+793>:	movslq %eax,%rdx
   0x0000555555559f86 <+796>:	mov    -0x290(%rbp),%eax
   0x0000555555559f8c <+802>:	movslq %eax,%rcx
   0x0000555555559f8f <+805>:	lea    -0x1e0(%rbp),%rax
   0x0000555555559f96 <+812>:	mov    %rcx,%rsi
   0x0000555555559f99 <+815>:	mov    %rax,%rdi
   0x0000555555559f9c <+818>:	call   0x55555555cf60 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELi1EEclEll>
   0x0000555555559fa1 <+823>:	movsd  -0x2c0(%rbp),%xmm4
   0x0000555555559fa9 <+831>:	movsd  %xmm4,(%rax)
   0x0000555555559fad <+835>:	movsd  -0x2c8(%rbp),%xmm5
   0x0000555555559fb5 <+843>:	movsd  %xmm5,0x8(%rax)

141	    }
142	
143	    // Build incidence matrix M (n x numEdges)
144	    Eigen::MatrixXcd M = Eigen::MatrixXcd::Zero(n, numEdges);
   0x0000555555559fd3 <+873>:	mov    -0x27c(%rbp),%eax
   0x0000555555559fd9 <+879>:	movslq %eax,%rdx
   0x0000555555559fdc <+882>:	mov    -0x2a0(%rbp),%eax
   0x0000555555559fe2 <+888>:	movslq %eax,%rcx
   0x0000555555559fe5 <+891>:	lea    -0xc0(%rbp),%rax
   0x0000555555559fec <+898>:	mov    %rcx,%rsi
   0x0000555555559fef <+901>:	mov    %rax,%rdi
   0x0000555555559ff2 <+904>:	call   0x55555555ad3a <Eigen::DenseBase<Eigen::Matrix<std::complex<double>, -1, -1, 0, -1, -1> >::Zero(Eigen::Index, Eigen::Index)>
   0x0000555555559ff7 <+909>:	lea    -0xc0(%rbp),%rdx
   0x0000555555559ffe <+916>:	lea    -0x1c0(%rbp),%rax
   0x000055555555a005 <+923>:	mov    %rdx,%rsi
   0x000055555555a008 <+926>:	mov    %rax,%rdi
   0x000055555555a00b <+929>:	call   0x55555555cdf6 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEC2INS_14CwiseNullaryOpINS_8internal18scalar_constant_opIS2_EES3_EEEERKNS_9EigenBaseIT_EE>

145	    for (int j = 0; j < numEdges; j++) {
   0x000055555555a010 <+934>:	movl   $0x0,-0x28c(%rbp)
   0x000055555555a01a <+944>:	jmp    0x55555555a107 <_ZN7Circuit8KCLSolveEv+1181>
   0x000055555555a100 <+1174>:	addl   $0x1,-0x28c(%rbp)
   0x000055555555a107 <+1181>:	mov    -0x28c(%rbp),%eax
   0x000055555555a10d <+1187>:	cmp    -0x27c(%rbp),%eax
   0x000055555555a113 <+1193>:	jl     0x55555555a01f <_ZN7Circuit8KCLSolveEv+949>

146		Bipole* bipole = bipoles[j];
   0x000055555555a01f <+949>:	mov    -0x2b8(%rbp),%rax
   0x000055555555a026 <+956>:	mov    -0x28c(%rbp),%edx
   0x000055555555a02c <+962>:	movslq %edx,%rdx
   0x000055555555a02f <+965>:	mov    %rdx,%rsi
   0x000055555555a032 <+968>:	mov    %rax,%rdi
   0x000055555555a035 <+971>:	call   0x55555555ced2 <_ZNSt6vectorIP6BipoleSaIS1_EEixEm>
   0x000055555555a03a <+976>:	mov    (%rax),%rax
   0x000055555555a03d <+979>:	mov    %rax,-0x248(%rbp)

147		int node1 = bipole->getNode1();
   0x000055555555a044 <+986>:	mov    -0x248(%rbp),%rax
   0x000055555555a04b <+993>:	mov    %rax,%rdi
   0x000055555555a04e <+996>:	call   0x55555555c86a <_ZNK6Bipole8getNode1Ev>
   0x000055555555a053 <+1001>:	mov    %eax,-0x268(%rbp)

148		int node2 = bipole->getNode2();
   0x000055555555a059 <+1007>:	mov    -0x248(%rbp),%rax
   0x000055555555a060 <+1014>:	mov    %rax,%rdi
   0x000055555555a063 <+1017>:	call   0x55555555c880 <_ZNK6Bipole8getNode2Ev>
   0x000055555555a068 <+1022>:	mov    %eax,-0x264(%rbp)

149		if (node1 != refNode) M(node1, j) = 1;
   0x000055555555a06e <+1028>:	mov    -0x268(%rbp),%eax
   0x000055555555a074 <+1034>:	cmp    -0x280(%rbp),%eax
   0x000055555555a07a <+1040>:	je     0x55555555a0b7 <_ZN7Circuit8KCLSolveEv+1101>
   0x000055555555a07c <+1042>:	mov    -0x28c(%rbp),%eax
   0x000055555555a082 <+1048>:	movslq %eax,%rdx
   0x000055555555a085 <+1051>:	mov    -0x268(%rbp),%eax
   0x000055555555a08b <+1057>:	movslq %eax,%rcx
   0x000055555555a08e <+1060>:	lea    -0x1c0(%rbp),%rax
   0x000055555555a095 <+1067>:	mov    %rcx,%rsi
   0x000055555555a098 <+1070>:	mov    %rax,%rdi
   0x000055555555a09b <+1073>:	call   0x55555555cf60 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELi1EEclEll>
   0x000055555555a0a0 <+1078>:	mov    %rax,%rdx
   0x000055555555a0a3 <+1081>:	mov    0xa8136(%rip),%rax        # 0x5555556021e0
   0x000055555555a0aa <+1088>:	movq   %rax,%xmm0
   0x000055555555a0af <+1093>:	mov    %rdx,%rdi
   0x000055555555a0b2 <+1096>:	call   0x555555558f06 <_ZNSt7complexIdEaSEd>

150		if (node2 != refNode) M(node2, j) = -1;
   0x000055555555a0b7 <+1101>:	mov    -0x264(%rbp),%eax
   0x000055555555a0bd <+1107>:	cmp    -0x280(%rbp),%eax
   0x000055555555a0c3 <+1113>:	je     0x55555555a100 <_ZN7Circuit8KCLSolveEv+1174>
   0x000055555555a0c5 <+1115>:	mov    -0x28c(%rbp),%eax
   0x000055555555a0cb <+1121>:	movslq %eax,%rdx
   0x000055555555a0ce <+1124>:	mov    -0x264(%rbp),%eax
   0x000055555555a0d4 <+1130>:	movslq %eax,%rcx
   0x000055555555a0d7 <+1133>:	lea    -0x1c0(%rbp),%rax
   0x000055555555a0de <+1140>:	mov    %rcx,%rsi
   0x000055555555a0e1 <+1143>:	mov    %rax,%rdi
   0x000055555555a0e4 <+1146>:	call   0x55555555cf60 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELi1EEclEll>
   0x000055555555a0e9 <+1151>:	mov    %rax,%rdx
   0x000055555555a0ec <+1154>:	mov    0xa80f5(%rip),%rax        # 0x5555556021e8
   0x000055555555a0f3 <+1161>:	movq   %rax,%xmm0
   0x000055555555a0f8 <+1166>:	mov    %rdx,%rdi
   0x000055555555a0fb <+1169>:	call   0x555555558f06 <_ZNSt7complexIdEaSEd>

151	    }
152	
153	    // Build matrix C for voltage sources (n x numVoltageSources)
154	    Eigen::MatrixXcd C = Eigen::MatrixXcd::Zero(n, numVoltageSources);
   0x000055555555a119 <+1199>:	mov    -0x298(%rbp),%eax
   0x000055555555a11f <+1205>:	movslq %eax,%rdx
   0x000055555555a122 <+1208>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a128 <+1214>:	movslq %eax,%rcx
   0x000055555555a12b <+1217>:	lea    -0xc0(%rbp),%rax
   0x000055555555a132 <+1224>:	mov    %rcx,%rsi
   0x000055555555a135 <+1227>:	mov    %rax,%rdi
   0x000055555555a138 <+1230>:	call   0x55555555ad3a <Eigen::DenseBase<Eigen::Matrix<std::complex<double>, -1, -1, 0, -1, -1> >::Zero(Eigen::Index, Eigen::Index)>
   0x000055555555a13d <+1235>:	lea    -0xc0(%rbp),%rdx
   0x000055555555a144 <+1242>:	lea    -0x1a0(%rbp),%rax
   0x000055555555a14b <+1249>:	mov    %rdx,%rsi
   0x000055555555a14e <+1252>:	mov    %rax,%rdi
   0x000055555555a151 <+1255>:	call   0x55555555cdf6 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEC2INS_14CwiseNullaryOpINS_8internal18scalar_constant_opIS2_EES3_EEEERKNS_9EigenBaseIT_EE>

155	    vsIndex = 0;
   0x000055555555a156 <+1260>:	movl   $0x0,-0x294(%rbp)

156	    for (int j = 0; j < numEdges; j++) {
   0x000055555555a160 <+1270>:	movl   $0x0,-0x288(%rbp)
   0x000055555555a16a <+1280>:	jmp    0x55555555a27b <_ZN7Circuit8KCLSolveEv+1553>
   0x000055555555a274 <+1546>:	addl   $0x1,-0x288(%rbp)
   0x000055555555a27b <+1553>:	mov    -0x288(%rbp),%eax
   0x000055555555a281 <+1559>:	cmp    -0x27c(%rbp),%eax
   0x000055555555a287 <+1565>:	jl     0x55555555a16f <_ZN7Circuit8KCLSolveEv+1285>

157		Bipole* bipole = bipoles[j];
   0x000055555555a16f <+1285>:	mov    -0x2b8(%rbp),%rax
   0x000055555555a176 <+1292>:	mov    -0x288(%rbp),%edx
   0x000055555555a17c <+1298>:	movslq %edx,%rdx
   0x000055555555a17f <+1301>:	mov    %rdx,%rsi
   0x000055555555a182 <+1304>:	mov    %rax,%rdi
   0x000055555555a185 <+1307>:	call   0x55555555ced2 <_ZNSt6vectorIP6BipoleSaIS1_EEixEm>
   0x000055555555a18a <+1312>:	mov    (%rax),%rax
   0x000055555555a18d <+1315>:	mov    %rax,-0x250(%rbp)

158		if (bipole->getType() == Type::VOLTAGE_SOURCE){
   0x000055555555a194 <+1322>:	mov    -0x250(%rbp),%rax
   0x000055555555a19b <+1329>:	mov    %rax,%rdi
   0x000055555555a19e <+1332>:	call   0x55555555c896 <_ZNK6Bipole7getTypeEv>
   0x000055555555a1a3 <+1337>:	cmp    $0x3,%eax
   0x000055555555a1a6 <+1340>:	sete   %al
   0x000055555555a1a9 <+1343>:	test   %al,%al
   0x000055555555a1ab <+1345>:	je     0x55555555a274 <_ZN7Circuit8KCLSolveEv+1546>

159		    int node1 = bipole->getNode1();
   0x000055555555a1b1 <+1351>:	mov    -0x250(%rbp),%rax
   0x000055555555a1b8 <+1358>:	mov    %rax,%rdi
   0x000055555555a1bb <+1361>:	call   0x55555555c86a <_ZNK6Bipole8getNode1Ev>
   0x000055555555a1c0 <+1366>:	mov    %eax,-0x270(%rbp)

160		    int node2 = bipole->getNode2();
   0x000055555555a1c6 <+1372>:	mov    -0x250(%rbp),%rax
   0x000055555555a1cd <+1379>:	mov    %rax,%rdi
   0x000055555555a1d0 <+1382>:	call   0x55555555c880 <_ZNK6Bipole8getNode2Ev>
   0x000055555555a1d5 <+1387>:	mov    %eax,-0x26c(%rbp)

161		    if (node1 != refNode) C(node1, vsIndex) = 1;
   0x000055555555a1db <+1393>:	mov    -0x270(%rbp),%eax
   0x000055555555a1e1 <+1399>:	cmp    -0x280(%rbp),%eax
   0x000055555555a1e7 <+1405>:	je     0x55555555a224 <_ZN7Circuit8KCLSolveEv+1466>
   0x000055555555a1e9 <+1407>:	mov    -0x294(%rbp),%eax
   0x000055555555a1ef <+1413>:	movslq %eax,%rdx
   0x000055555555a1f2 <+1416>:	mov    -0x270(%rbp),%eax
   0x000055555555a1f8 <+1422>:	movslq %eax,%rcx
   0x000055555555a1fb <+1425>:	lea    -0x1a0(%rbp),%rax
   0x000055555555a202 <+1432>:	mov    %rcx,%rsi
   0x000055555555a205 <+1435>:	mov    %rax,%rdi
   0x000055555555a208 <+1438>:	call   0x55555555cf60 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELi1EEclEll>
   0x000055555555a20d <+1443>:	mov    %rax,%rdx
   0x000055555555a210 <+1446>:	mov    0xa7fc9(%rip),%rax        # 0x5555556021e0
   0x000055555555a217 <+1453>:	movq   %rax,%xmm0
   0x000055555555a21c <+1458>:	mov    %rdx,%rdi
   0x000055555555a21f <+1461>:	call   0x555555558f06 <_ZNSt7complexIdEaSEd>

162		    if (node2 != refNode) C(node2, vsIndex) = -1;
   0x000055555555a224 <+1466>:	mov    -0x26c(%rbp),%eax
   0x000055555555a22a <+1472>:	cmp    -0x280(%rbp),%eax
   0x000055555555a230 <+1478>:	je     0x55555555a26d <_ZN7Circuit8KCLSolveEv+1539>
   0x000055555555a232 <+1480>:	mov    -0x294(%rbp),%eax
   0x000055555555a238 <+1486>:	movslq %eax,%rdx
   0x000055555555a23b <+1489>:	mov    -0x26c(%rbp),%eax
   0x000055555555a241 <+1495>:	movslq %eax,%rcx
   0x000055555555a244 <+1498>:	lea    -0x1a0(%rbp),%rax
   0x000055555555a24b <+1505>:	mov    %rcx,%rsi
   0x000055555555a24e <+1508>:	mov    %rax,%rdi
   0x000055555555a251 <+1511>:	call   0x55555555cf60 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELi1EEclEll>
   0x000055555555a256 <+1516>:	mov    %rax,%rdx
   0x000055555555a259 <+1519>:	mov    0xa7f88(%rip),%rax        # 0x5555556021e8
   0x000055555555a260 <+1526>:	movq   %rax,%xmm0
   0x000055555555a265 <+1531>:	mov    %rdx,%rdi
   0x000055555555a268 <+1534>:	call   0x555555558f06 <_ZNSt7complexIdEaSEd>

163		    vsIndex++;
   0x000055555555a26d <+1539>:	addl   $0x1,-0x294(%rbp)

164		}
165	    }
166	
167	    // Remove reference node from M and C
168	    Eigen::MatrixXcd M_reduced = M.bottomRows(n - 1);
   0x000055555555a28d <+1571>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a293 <+1577>:	lea    -0x1(%rax),%edx
   0x000055555555a296 <+1580>:	lea    -0xc0(%rbp),%rax
   0x000055555555a29d <+1587>:	lea    -0x1c0(%rbp),%rcx
   0x000055555555a2a4 <+1594>:	mov    %rcx,%rsi
   0x000055555555a2a7 <+1597>:	mov    %rax,%rdi
   0x000055555555a2aa <+1600>:	call   0x55555555d06a <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE10bottomRowsIiEENS5_13NRowsBlockXprIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEE4TypeESA_>
   0x000055555555a2af <+1605>:	lea    -0xc0(%rbp),%rdx
   0x000055555555a2b6 <+1612>:	lea    -0x180(%rbp),%rax
   0x000055555555a2bd <+1619>:	mov    %rdx,%rsi
   0x000055555555a2c0 <+1622>:	mov    %rax,%rdi
   0x000055555555a2c3 <+1625>:	call   0x55555555d0fa <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEC2INS_5BlockIS3_Lin1ELin1ELb0EEEEERKNS_9EigenBaseIT_EE>

169	    Eigen::MatrixXcd C_reduced = C.bottomRows(n - 1);
   0x000055555555a2c8 <+1630>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a2ce <+1636>:	lea    -0x1(%rax),%edx
   0x000055555555a2d1 <+1639>:	lea    -0xc0(%rbp),%rax
   0x000055555555a2d8 <+1646>:	lea    -0x1a0(%rbp),%rcx
   0x000055555555a2df <+1653>:	mov    %rcx,%rsi
   0x000055555555a2e2 <+1656>:	mov    %rax,%rdi
   0x000055555555a2e5 <+1659>:	call   0x55555555d06a <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE10bottomRowsIiEENS5_13NRowsBlockXprIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEE4TypeESA_>
   0x000055555555a2ea <+1664>:	lea    -0xc0(%rbp),%rdx
   0x000055555555a2f1 <+1671>:	lea    -0x160(%rbp),%rax
   0x000055555555a2f8 <+1678>:	mov    %rdx,%rsi
   0x000055555555a2fb <+1681>:	mov    %rax,%rdi
   0x000055555555a2fe <+1684>:	call   0x55555555d0fa <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEC2INS_5BlockIS3_Lin1ELin1ELb0EEEEERKNS_9EigenBaseIT_EE>

170	
171	    // Build the augmented system
172	    int augSize = n - 1 + numVoltageSources;
   0x000055555555a303 <+1689>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a309 <+1695>:	lea    -0x1(%rax),%edx
   0x000055555555a30c <+1698>:	mov    -0x298(%rbp),%eax
   0x000055555555a312 <+1704>:	add    %edx,%eax
   0x000055555555a314 <+1706>:	mov    %eax,-0x29c(%rbp)

173	    Eigen::MatrixXcd A_aug(augSize, augSize);
   0x000055555555a31a <+1712>:	lea    -0x29c(%rbp),%rdx
   0x000055555555a321 <+1719>:	lea    -0x29c(%rbp),%rcx
   0x000055555555a328 <+1726>:	lea    -0x140(%rbp),%rax
   0x000055555555a32f <+1733>:	mov    %rcx,%rsi
   0x000055555555a332 <+1736>:	mov    %rax,%rdi
   0x000055555555a335 <+1739>:	call   0x55555555d132 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEC2IiiEERKT_RKT0_>

174	    Eigen::VectorXcd b_aug(augSize);
   0x000055555555a33a <+1744>:	lea    -0x29c(%rbp),%rdx
   0x000055555555a341 <+1751>:	lea    -0x220(%rbp),%rax
   0x000055555555a348 <+1758>:	mov    %rdx,%rsi
   0x000055555555a34b <+1761>:	mov    %rax,%rdi
   0x000055555555a34e <+1764>:	call   0x55555555d1a6 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEC2IiEERKT_>

175	    A_aug.setZero();
   0x000055555555a353 <+1769>:	lea    -0x140(%rbp),%rax
   0x000055555555a35a <+1776>:	mov    %rax,%rdi
   0x000055555555a35d <+1779>:	call   0x55555555d210 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE7setZeroEv>

176	    b_aug.setZero();
   0x000055555555a362 <+1784>:	lea    -0x220(%rbp),%rax
   0x000055555555a369 <+1791>:	mov    %rax,%rdi
   0x000055555555a36c <+1794>:	call   0x55555555d274 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEEE7setZeroEv>

177	
178	    // Top-left block: M_reduced * Y * M_reduced
179	    A_aug.topLeftCorner(n-1, n-1) = M_reduced * Y * M_reduced.adjoint();
   0x000055555555a371 <+1799>:	lea    -0x120(%rbp),%rax
   0x000055555555a378 <+1806>:	lea    -0x180(%rbp),%rdx
   0x000055555555a37f <+1813>:	mov    %rdx,%rsi
   0x000055555555a382 <+1816>:	mov    %rax,%rdi
   0x000055555555a385 <+1819>:	call   0x55555555d3c2 <_ZNK5Eigen10MatrixBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE7adjointEv>
   0x000055555555a38a <+1824>:	lea    -0x1e0(%rbp),%rdx
   0x000055555555a391 <+1831>:	lea    -0x180(%rbp),%rax
   0x000055555555a398 <+1838>:	mov    %rdx,%rsi
   0x000055555555a39b <+1841>:	mov    %rax,%rdi
   0x000055555555a39e <+1844>:	call   0x55555555d34c <_ZNK5Eigen10MatrixBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEEmlIS4_EEKNS_7ProductIS4_T_Li0EEERKNS0_IS8_EE>
   0x000055555555a3a3 <+1849>:	mov    %rax,-0x1f0(%rbp)
   0x000055555555a3aa <+1856>:	mov    %rdx,-0x1e8(%rbp)
   0x000055555555a3b1 <+1863>:	lea    -0x100(%rbp),%rax
   0x000055555555a3b8 <+1870>:	lea    -0x120(%rbp),%rdx
   0x000055555555a3bf <+1877>:	lea    -0x1f0(%rbp),%rcx
   0x000055555555a3c6 <+1884>:	mov    %rcx,%rsi
   0x000055555555a3c9 <+1887>:	mov    %rax,%rdi
   0x000055555555a3cc <+1890>:	call   0x55555555d432 <_ZNK5Eigen10MatrixBaseINS_7ProductINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEES5_Li0EEEEmlINS_12CwiseUnaryOpINS_8internal19scalar_conjugate_opIS4_EEKNS_9TransposeIKS5_EEEEEEKNS1_IS6_T_Li0EEERKNS0_ISI_EE>
   0x000055555555a3d1 <+1895>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a3d7 <+1901>:	lea    -0x1(%rax),%ecx
   0x000055555555a3da <+1904>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a3e0 <+1910>:	lea    -0x1(%rax),%edx
   0x000055555555a3e3 <+1913>:	lea    -0xc0(%rbp),%rax
   0x000055555555a3ea <+1920>:	lea    -0x140(%rbp),%rsi
   0x000055555555a3f1 <+1927>:	mov    %rax,%rdi
   0x000055555555a3f4 <+1930>:	call   0x55555555d2d8 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE13topLeftCornerIiiEENS5_13FixedBlockXprIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEXsrNS9_IT0_Lin1EEE5valueEE4TypeESA_SC_>
   0x000055555555a3f9 <+1935>:	lea    -0x100(%rbp),%rdx
   0x000055555555a400 <+1942>:	lea    -0xc0(%rbp),%rax
   0x000055555555a407 <+1949>:	mov    %rdx,%rsi
   0x000055555555a40a <+1952>:	mov    %rax,%rdi
   0x000055555555a40d <+1955>:	call   0x55555555d486 <_ZN5Eigen10MatrixBaseINS_5BlockINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELin1ELin1ELb0EEEEaSINS_7ProductINS9_IS5_S5_Li0EEENS_12CwiseUnaryOpINS_8internal19scalar_conjugate_opIS4_EEKNS_9TransposeIKS5_EEEELi0EEEEERS6_RKNS_9DenseBaseIT_EE>

180	    // Top-right block: C_reduced
181	    A_aug.topRightCorner(n-1, numVoltageSources) = C_reduced;
   0x000055555555a412 <+1960>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a418 <+1966>:	lea    -0x1(%rax),%edi
   0x000055555555a41b <+1969>:	lea    -0xc0(%rbp),%rax
   0x000055555555a422 <+1976>:	mov    -0x298(%rbp),%edx
   0x000055555555a428 <+1982>:	lea    -0x140(%rbp),%rsi
   0x000055555555a42f <+1989>:	mov    %edx,%ecx
   0x000055555555a431 <+1991>:	mov    %edi,%edx
   0x000055555555a433 <+1993>:	mov    %rax,%rdi
   0x000055555555a436 <+1996>:	call   0x55555555d4d4 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE14topRightCornerIiiEENS5_13FixedBlockXprIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEXsrNS9_IT0_Lin1EEE5valueEE4TypeESA_SC_>
   0x000055555555a43b <+2001>:	lea    -0x160(%rbp),%rdx
   0x000055555555a442 <+2008>:	lea    -0xc0(%rbp),%rax
   0x000055555555a449 <+2015>:	mov    %rdx,%rsi
   0x000055555555a44c <+2018>:	mov    %rax,%rdi
   0x000055555555a44f <+2021>:	call   0x55555555d568 <_ZN5Eigen10MatrixBaseINS_5BlockINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELin1ELin1ELb0EEEEaSIS5_EERS6_RKNS_9DenseBaseIT_EE>

182	    // Bottom-left block: C_reduced^t
183	    A_aug.bottomLeftCorner(numVoltageSources, n-1) = C_reduced.adjoint();
   0x000055555555a454 <+2026>:	lea    -0x100(%rbp),%rax
   0x000055555555a45b <+2033>:	lea    -0x160(%rbp),%rdx
   0x000055555555a462 <+2040>:	mov    %rdx,%rsi
   0x000055555555a465 <+2043>:	mov    %rax,%rdi
   0x000055555555a468 <+2046>:	call   0x55555555d3c2 <_ZNK5Eigen10MatrixBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE7adjointEv>
   0x000055555555a46d <+2051>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a473 <+2057>:	lea    -0x1(%rax),%ecx
   0x000055555555a476 <+2060>:	lea    -0xc0(%rbp),%rax
   0x000055555555a47d <+2067>:	mov    -0x298(%rbp),%edx
   0x000055555555a483 <+2073>:	lea    -0x140(%rbp),%rsi
   0x000055555555a48a <+2080>:	mov    %rax,%rdi
   0x000055555555a48d <+2083>:	call   0x55555555d5b6 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE16bottomLeftCornerIiiEENS5_13FixedBlockXprIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEXsrNS9_IT0_Lin1EEE5valueEE4TypeESA_SC_>
   0x000055555555a492 <+2088>:	lea    -0x100(%rbp),%rdx
   0x000055555555a499 <+2095>:	lea    -0xc0(%rbp),%rax
   0x000055555555a4a0 <+2102>:	mov    %rdx,%rsi
   0x000055555555a4a3 <+2105>:	mov    %rax,%rdi
   0x000055555555a4a6 <+2108>:	call   0x55555555d64a <_ZN5Eigen10MatrixBaseINS_5BlockINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELin1ELin1ELb0EEEEaSINS_12CwiseUnaryOpINS_8internal19scalar_conjugate_opIS4_EEKNS_9TransposeIKS5_EEEEEERS6_RKNS_9DenseBaseIT_EE>

184	    // Bottom-right block: zero
185	    A_aug.bottomRightCorner(numVoltageSources, numVoltageSources).setZero();
   0x000055555555a4ab <+2113>:	lea    -0xc0(%rbp),%rax
   0x000055555555a4b2 <+2120>:	mov    -0x298(%rbp),%ecx
   0x000055555555a4b8 <+2126>:	mov    -0x298(%rbp),%edx
   0x000055555555a4be <+2132>:	lea    -0x140(%rbp),%rsi
   0x000055555555a4c5 <+2139>:	mov    %rax,%rdi
   0x000055555555a4c8 <+2142>:	call   0x55555555d698 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE17bottomRightCornerIiiEENS5_13FixedBlockXprIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEXsrNS9_IT0_Lin1EEE5valueEE4TypeESA_SC_>
   0x000055555555a4cd <+2147>:	lea    -0xc0(%rbp),%rax
   0x000055555555a4d4 <+2154>:	mov    %rax,%rdi
   0x000055555555a4d7 <+2157>:	call   0x55555555d74e <_ZN5Eigen9DenseBaseINS_5BlockINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEELin1ELin1ELb0EEEE7setZeroEv>

186	
187	    // Build right-hand side vector
188	    b_aug.head(n-1) = -M_reduced * Y * V_S;
   0x000055555555a4dc <+2162>:	lea    -0x1f0(%rbp),%rax
   0x000055555555a4e3 <+2169>:	lea    -0x180(%rbp),%rdx
   0x000055555555a4ea <+2176>:	mov    %rdx,%rsi
   0x000055555555a4ed <+2179>:	mov    %rax,%rdi
   0x000055555555a4f0 <+2182>:	call   0x55555555d806 <_ZNK5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEEngEv>
   0x000055555555a4f5 <+2187>:	lea    -0x120(%rbp),%rax
   0x000055555555a4fc <+2194>:	lea    -0x1e0(%rbp),%rdx
   0x000055555555a503 <+2201>:	lea    -0x1f0(%rbp),%rcx
   0x000055555555a50a <+2208>:	mov    %rcx,%rsi
   0x000055555555a50d <+2211>:	mov    %rax,%rdi
   0x000055555555a510 <+2214>:	call   0x55555555d872 <_ZNK5Eigen10MatrixBaseINS_12CwiseUnaryOpINS_8internal18scalar_opposite_opISt7complexIdEEEKNS_6MatrixIS5_Lin1ELin1ELi0ELin1ELin1EEEEEEmlIS8_EEKNS_7ProductISA_T_Li0EEERKNS0_ISE_EE>
   0x000055555555a515 <+2219>:	lea    -0x100(%rbp),%rax
   0x000055555555a51c <+2226>:	lea    -0x230(%rbp),%rdx
   0x000055555555a523 <+2233>:	lea    -0x120(%rbp),%rcx
   0x000055555555a52a <+2240>:	mov    %rcx,%rsi
   0x000055555555a52d <+2243>:	mov    %rax,%rdi
   0x000055555555a530 <+2246>:	call   0x55555555d8c6 <_ZNK5Eigen10MatrixBaseINS_7ProductINS_12CwiseUnaryOpINS_8internal18scalar_opposite_opISt7complexIdEEEKNS_6MatrixIS6_Lin1ELin1ELi0ELin1ELin1EEEEES9_Li0EEEEmlINS8_IS6_Lin1ELi1ELi0ELin1ELi1EEEEEKNS1_ISC_T_Li0EEERKNS0_ISG_EE>
   0x000055555555a535 <+2251>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a53b <+2257>:	lea    -0x1(%rax),%edx
   0x000055555555a53e <+2260>:	lea    -0xc0(%rbp),%rax
   0x000055555555a545 <+2267>:	lea    -0x220(%rbp),%rcx
   0x000055555555a54c <+2274>:	mov    %rcx,%rsi
   0x000055555555a54f <+2277>:	mov    %rax,%rdi
   0x000055555555a552 <+2280>:	call   0x55555555d7b2 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEEE4headIiEENS5_22FixedSegmentReturnTypeIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEE4TypeESA_>
   0x000055555555a557 <+2285>:	lea    -0x100(%rbp),%rdx
   0x000055555555a55e <+2292>:	lea    -0xc0(%rbp),%rax
   0x000055555555a565 <+2299>:	mov    %rdx,%rsi
   0x000055555555a568 <+2302>:	mov    %rax,%rdi
   0x000055555555a56b <+2305>:	call   0x55555555d91a <_ZN5Eigen10MatrixBaseINS_5BlockINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELin1ELi1ELb0EEEEaSINS_7ProductINS9_INS_12CwiseUnaryOpINS_8internal18scalar_opposite_opIS4_EEKNS2_IS4_Lin1ELin1ELi0ELin1ELin1EEEEESE_Li0EEES5_Li0EEEEERS6_RKNS_9DenseBaseIT_EE>

189	    b_aug.tail(numVoltageSources) = V_S;
   0x000055555555a570 <+2310>:	lea    -0xc0(%rbp),%rax
   0x000055555555a577 <+2317>:	mov    -0x298(%rbp),%edx
   0x000055555555a57d <+2323>:	lea    -0x220(%rbp),%rcx
   0x000055555555a584 <+2330>:	mov    %rcx,%rsi
   0x000055555555a587 <+2333>:	mov    %rax,%rdi
   0x000055555555a58a <+2336>:	call   0x55555555d968 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEEE4tailIiEENS5_22FixedSegmentReturnTypeIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEE4TypeESA_>
   0x000055555555a58f <+2341>:	lea    -0x230(%rbp),%rdx
   0x000055555555a596 <+2348>:	lea    -0xc0(%rbp),%rax
   0x000055555555a59d <+2355>:	mov    %rdx,%rsi
   0x000055555555a5a0 <+2358>:	mov    %rax,%rdi
   0x000055555555a5a3 <+2361>:	call   0x55555555d9de <_ZN5Eigen10MatrixBaseINS_5BlockINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELin1ELi1ELb0EEEEaSIS5_EERS6_RKNS_9DenseBaseIT_EE>

190	
191	    // Solve the system
192	    Eigen::VectorXcd x_aug = A_aug.colPivHouseholderQr().solve(b_aug);
   0x000055555555a5a8 <+2366>:	lea    -0xc0(%rbp),%rax
   0x000055555555a5af <+2373>:	lea    -0x140(%rbp),%rdx
   0x000055555555a5b6 <+2380>:	mov    %rdx,%rsi
   0x000055555555a5b9 <+2383>:	mov    %rax,%rdi
   0x000055555555a5bc <+2386>:	call   0x55555555da2c <_ZNK5Eigen10MatrixBaseINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEE19colPivHouseholderQrEv>
   0x000055555555a5c1 <+2391>:	lea    -0x220(%rbp),%rdx
   0x000055555555a5c8 <+2398>:	lea    -0xc0(%rbp),%rax
   0x000055555555a5cf <+2405>:	mov    %rdx,%rsi
   0x000055555555a5d2 <+2408>:	mov    %rax,%rdi
   0x000055555555a5d5 <+2411>:	call   0x55555555db34 <_ZNK5Eigen10SolverBaseINS_19ColPivHouseholderQRINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEEEE5solveINS2_IS4_Lin1ELi1ELi0ELin1ELi1EEEEEKNS_5SolveIS6_T_EERKNS_10MatrixBaseISB_EE>
   0x000055555555a5da <+2416>:	mov    %rax,-0x100(%rbp)
   0x000055555555a5e1 <+2423>:	mov    %rdx,-0xf8(%rbp)
   0x000055555555a5e8 <+2430>:	lea    -0x100(%rbp),%rdx
   0x000055555555a5ef <+2437>:	lea    -0x210(%rbp),%rax
   0x000055555555a5f6 <+2444>:	mov    %rdx,%rsi
   0x000055555555a5f9 <+2447>:	mov    %rax,%rdi
   0x000055555555a5fc <+2450>:	call   0x55555555dbc8 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEC2INS_5SolveINS_19ColPivHouseholderQRINS0_IS2_Lin1ELin1ELi0ELin1ELin1EEEEES3_EEEERKNS_9EigenBaseIT_EE>
   0x000055555555a601 <+2455>:	lea    -0xc0(%rbp),%rax
   0x000055555555a608 <+2462>:	mov    %rax,%rdi
   0x000055555555a60b <+2465>:	call   0x55555555ca84 <_ZN5Eigen19ColPivHouseholderQRINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEED2Ev>
   0x000055555555a9b4 <+3402>:	mov    %rax,%rbx
   0x000055555555a9b7 <+3405>:	lea    -0xc0(%rbp),%rax
   0x000055555555a9be <+3412>:	mov    %rax,%rdi
   0x000055555555a9c1 <+3415>:	call   0x55555555ca84 <_ZN5Eigen19ColPivHouseholderQRINS_6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EEEED2Ev>
   0x000055555555a9c6 <+3420>:	jmp    0x55555555a9ff <_ZN7Circuit8KCLSolveEv+3477>
   0x000055555555a9c8 <+3422>:	endbr64

193	
194	    // Extract node voltages (excluding reference node)
195	    Eigen::VectorXcd nodeVoltages(n);
   0x000055555555a610 <+2470>:	lea    -0x2a0(%rbp),%rdx
   0x000055555555a617 <+2477>:	lea    -0x200(%rbp),%rax
   0x000055555555a61e <+2484>:	mov    %rdx,%rsi
   0x000055555555a621 <+2487>:	mov    %rax,%rdi
   0x000055555555a624 <+2490>:	call   0x55555555d1a6 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEC2IiEERKT_>

196	    nodeVoltages(refNode) = 0;
   0x000055555555a629 <+2495>:	mov    -0x280(%rbp),%eax
   0x000055555555a62f <+2501>:	movslq %eax,%rdx
   0x000055555555a632 <+2504>:	lea    -0x200(%rbp),%rax
   0x000055555555a639 <+2511>:	mov    %rdx,%rsi
   0x000055555555a63c <+2514>:	mov    %rax,%rdi
   0x000055555555a63f <+2517>:	call   0x55555555dc00 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELi1EEclEl>
   0x000055555555a644 <+2522>:	mov    %rax,%rdx
   0x000055555555a647 <+2525>:	mov    0xa7b8a(%rip),%rax        # 0x5555556021d8
   0x000055555555a64e <+2532>:	movq   %rax,%xmm0
   0x000055555555a653 <+2537>:	mov    %rdx,%rdi
   0x000055555555a656 <+2540>:	call   0x555555558f06 <_ZNSt7complexIdEaSEd>

197	    nodeVoltages.tail(n-1) = x_aug.head(n-1);
   0x000055555555a65b <+2545>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a661 <+2551>:	lea    -0x1(%rax),%edx
   0x000055555555a664 <+2554>:	lea    -0xc0(%rbp),%rax
   0x000055555555a66b <+2561>:	lea    -0x210(%rbp),%rcx
   0x000055555555a672 <+2568>:	mov    %rcx,%rsi
   0x000055555555a675 <+2571>:	mov    %rax,%rdi
   0x000055555555a678 <+2574>:	call   0x55555555d7b2 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEEE4headIiEENS5_22FixedSegmentReturnTypeIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEE4TypeESA_>
   0x000055555555a67d <+2579>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a683 <+2585>:	lea    -0x1(%rax),%edx
   0x000055555555a686 <+2588>:	lea    -0x100(%rbp),%rax
   0x000055555555a68d <+2595>:	lea    -0x200(%rbp),%rcx
   0x000055555555a694 <+2602>:	mov    %rcx,%rsi
   0x000055555555a697 <+2605>:	mov    %rax,%rdi
   0x000055555555a69a <+2608>:	call   0x55555555d968 <_ZN5Eigen9DenseBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEEE4tailIiEENS5_22FixedSegmentReturnTypeIXsrNS_8internal15get_fixed_valueIT_Lin1EEE5valueEE4TypeESA_>
   0x000055555555a69f <+2613>:	lea    -0xc0(%rbp),%rdx
   0x000055555555a6a6 <+2620>:	lea    -0x100(%rbp),%rax
   0x000055555555a6ad <+2627>:	mov    %rdx,%rsi
   0x000055555555a6b0 <+2630>:	mov    %rax,%rdi
   0x000055555555a6b3 <+2633>:	call   0x55555555cb10 <_ZN5Eigen11VectorBlockINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELin1EEaSEOS5_>

198	
199	    // Update bipole voltages and currents
200	    for (int j = 0; j < numEdges; j++) {
   0x000055555555a6b8 <+2638>:	movl   $0x0,-0x284(%rbp)
   0x000055555555a6c2 <+2648>:	jmp    0x55555555a8f0 <_ZN7Circuit8KCLSolveEv+3206>
   0x000055555555a8e9 <+3199>:	addl   $0x1,-0x284(%rbp)
   0x000055555555a8f0 <+3206>:	mov    -0x284(%rbp),%eax
   0x000055555555a8f6 <+3212>:	cmp    -0x27c(%rbp),%eax
   0x000055555555a8fc <+3218>:	jl     0x55555555a6c7 <_ZN7Circuit8KCLSolveEv+2653>

201		Bipole* bipole = bipoles[j];
   0x000055555555a6c7 <+2653>:	mov    -0x2b8(%rbp),%rax
   0x000055555555a6ce <+2660>:	mov    -0x284(%rbp),%edx
   0x000055555555a6d4 <+2666>:	movslq %edx,%rdx
   0x000055555555a6d7 <+2669>:	mov    %rdx,%rsi
   0x000055555555a6da <+2672>:	mov    %rax,%rdi
   0x000055555555a6dd <+2675>:	call   0x55555555ced2 <_ZNSt6vectorIP6BipoleSaIS1_EEixEm>
   0x000055555555a6e2 <+2680>:	mov    (%rax),%rax
   0x000055555555a6e5 <+2683>:	mov    %rax,-0x258(%rbp)

202		int node1 = bipole->getNode1();
   0x000055555555a6ec <+2690>:	mov    -0x258(%rbp),%rax
   0x000055555555a6f3 <+2697>:	mov    %rax,%rdi
   0x000055555555a6f6 <+2700>:	call   0x55555555c86a <_ZNK6Bipole8getNode1Ev>
   0x000055555555a6fb <+2705>:	mov    %eax,-0x278(%rbp)

203		int node2 = bipole->getNode2();
   0x000055555555a701 <+2711>:	mov    -0x258(%rbp),%rax
   0x000055555555a708 <+2718>:	mov    %rax,%rdi
   0x000055555555a70b <+2721>:	call   0x55555555c880 <_ZNK6Bipole8getNode2Ev>
   0x000055555555a710 <+2726>:	mov    %eax,-0x274(%rbp)

204		std::complex<double> v1 = (node1 == refNode) ? 0 : nodeVoltages(node1);
   0x000055555555a716 <+2732>:	mov    -0x278(%rbp),%eax
   0x000055555555a71c <+2738>:	cmp    -0x280(%rbp),%eax
   0x000055555555a722 <+2744>:	jne    0x55555555a745 <_ZN7Circuit8KCLSolveEv+2779>
   0x000055555555a724 <+2746>:	lea    -0x1f0(%rbp),%rax
   0x000055555555a72b <+2753>:	pxor   %xmm1,%xmm1
   0x000055555555a72f <+2757>:	mov    0xa7aa2(%rip),%rdx        # 0x5555556021d8
   0x000055555555a736 <+2764>:	movq   %rdx,%xmm0
   0x000055555555a73b <+2769>:	mov    %rax,%rdi
   0x000055555555a73e <+2772>:	call   0x555555556c00 <_ZNSt7complexIdEC2Edd>
   0x000055555555a743 <+2777>:	jmp    0x55555555a779 <_ZN7Circuit8KCLSolveEv+2831>
   0x000055555555a745 <+2779>:	mov    -0x278(%rbp),%eax
   0x000055555555a74b <+2785>:	movslq %eax,%rdx
   0x000055555555a74e <+2788>:	lea    -0x200(%rbp),%rax
   0x000055555555a755 <+2795>:	mov    %rdx,%rsi
   0x000055555555a758 <+2798>:	mov    %rax,%rdi
   0x000055555555a75b <+2801>:	call   0x55555555dc00 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELi1EEclEl>
   0x000055555555a760 <+2806>:	movsd  (%rax),%xmm0
   0x000055555555a764 <+2810>:	movsd  %xmm0,-0x1f0(%rbp)
   0x000055555555a76c <+2818>:	movsd  0x8(%rax),%xmm0
   0x000055555555a771 <+2823>:	movsd  %xmm0,-0x1e8(%rbp)

205		std::complex<double> v2 = (node2 == refNode) ? 0 : nodeVoltages(node2);
   0x000055555555a779 <+2831>:	mov    -0x274(%rbp),%eax
   0x000055555555a77f <+2837>:	cmp    -0x280(%rbp),%eax
   0x000055555555a785 <+2843>:	jne    0x55555555a7a8 <_ZN7Circuit8KCLSolveEv+2878>
   0x000055555555a787 <+2845>:	lea    -0x120(%rbp),%rax
   0x000055555555a78e <+2852>:	pxor   %xmm1,%xmm1
   0x000055555555a792 <+2856>:	mov    0xa7a3f(%rip),%rdx        # 0x5555556021d8
   0x000055555555a799 <+2863>:	movq   %rdx,%xmm0
   0x000055555555a79e <+2868>:	mov    %rax,%rdi
   0x000055555555a7a1 <+2871>:	call   0x555555556c00 <_ZNSt7complexIdEC2Edd>
   0x000055555555a7a6 <+2876>:	jmp    0x55555555a7dc <_ZN7Circuit8KCLSolveEv+2930>
   0x000055555555a7a8 <+2878>:	mov    -0x274(%rbp),%eax
   0x000055555555a7ae <+2884>:	movslq %eax,%rdx
   0x000055555555a7b1 <+2887>:	lea    -0x200(%rbp),%rax
   0x000055555555a7b8 <+2894>:	mov    %rdx,%rsi
   0x000055555555a7bb <+2897>:	mov    %rax,%rdi
   0x000055555555a7be <+2900>:	call   0x55555555dc00 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELi1EEclEl>
   0x000055555555a7c3 <+2905>:	movsd  (%rax),%xmm0
   0x000055555555a7c7 <+2909>:	movsd  %xmm0,-0x120(%rbp)
   0x000055555555a7cf <+2917>:	movsd  0x8(%rax),%xmm0
   0x000055555555a7d4 <+2922>:	movsd  %xmm0,-0x118(%rbp)

206		bipole->setVoltage(v1 - v2);
   0x000055555555a7dc <+2930>:	mov    -0x258(%rbp),%rbx
   0x000055555555a7e3 <+2937>:	lea    -0x120(%rbp),%rdx
   0x000055555555a7ea <+2944>:	lea    -0x1f0(%rbp),%rax
   0x000055555555a7f1 <+2951>:	mov    %rdx,%rsi
   0x000055555555a7f4 <+2954>:	mov    %rax,%rdi
   0x000055555555a7f7 <+2957>:	call   0x55555555dc97 <_ZStmiIdESt7complexIT_ERKS2_S4_>
   0x000055555555a7fc <+2962>:	mov    %rbx,%rdi
   0x000055555555a7ff <+2965>:	call   0x555555558f60 <_ZN6Bipole10setVoltageESt7complexIdE>

207		if (bipole->getType() != Type::VOLTAGE_SOURCE) {
   0x000055555555a804 <+2970>:	mov    -0x258(%rbp),%rax
   0x000055555555a80b <+2977>:	mov    %rax,%rdi
   0x000055555555a80e <+2980>:	call   0x55555555c896 <_ZNK6Bipole7getTypeEv>
   0x000055555555a813 <+2985>:	cmp    $0x3,%eax
   0x000055555555a816 <+2988>:	setne  %al
   0x000055555555a819 <+2991>:	test   %al,%al
   0x000055555555a81b <+2993>:	je     0x55555555a8a7 <_ZN7Circuit8KCLSolveEv+3133>

208		    bipole->setCurrent(bipole->getVoltage() / bipole->getImpedance());
   0x000055555555a821 <+2999>:	mov    -0x258(%rbp),%rbx
   0x000055555555a828 <+3006>:	mov    -0x258(%rbp),%rax
   0x000055555555a82f <+3013>:	mov    (%rax),%rax
   0x000055555555a832 <+3016>:	add    $0x10,%rax
   0x000055555555a836 <+3020>:	mov    (%rax),%rdx
   0x000055555555a839 <+3023>:	mov    -0x258(%rbp),%rax
   0x000055555555a840 <+3030>:	mov    %rax,%rdi
   0x000055555555a843 <+3033>:	call   *%rdx
   0x000055555555a845 <+3035>:	movq   %xmm0,%rax
   0x000055555555a84a <+3040>:	movapd %xmm1,%xmm0
   0x000055555555a84e <+3044>:	mov    %rax,-0xc0(%rbp)
   0x000055555555a855 <+3051>:	movsd  %xmm0,-0xb8(%rbp)
   0x000055555555a85d <+3059>:	mov    -0x258(%rbp),%rax
   0x000055555555a864 <+3066>:	mov    %rax,%rdi
   0x000055555555a867 <+3069>:	call   0x555555558f38 <_ZNK6Bipole10getVoltageEv>
   0x000055555555a86c <+3074>:	movq   %xmm0,%rax
   0x000055555555a871 <+3079>:	movapd %xmm1,%xmm0
   0x000055555555a875 <+3083>:	mov    %rax,-0x100(%rbp)
   0x000055555555a87c <+3090>:	movsd  %xmm0,-0xf8(%rbp)
   0x000055555555a884 <+3098>:	lea    -0xc0(%rbp),%rdx
   0x000055555555a88b <+3105>:	lea    -0x100(%rbp),%rax
   0x000055555555a892 <+3112>:	mov    %rdx,%rsi
   0x000055555555a895 <+3115>:	mov    %rax,%rdi
   0x000055555555a898 <+3118>:	call   0x55555555748f <_ZStdvIdESt7complexIT_ERKS2_S4_>
   0x000055555555a89d <+3123>:	mov    %rbx,%rdi
   0x000055555555a8a0 <+3126>:	call   0x555555558fc6 <_ZN6Bipole10setCurrentESt7complexIdE>
   0x000055555555a8a5 <+3131>:	jmp    0x55555555a8e9 <_ZN7Circuit8KCLSolveEv+3199>

209		} else {
210		    // Current for voltage sources is taken from solution
211		    bipole->setCurrent(x_aug(n-1 + vsIndex));
   0x000055555555a8a7 <+3133>:	mov    -0x258(%rbp),%rbx
   0x000055555555a8ae <+3140>:	mov    -0x2a0(%rbp),%eax
   0x000055555555a8b4 <+3146>:	lea    -0x1(%rax),%edx
   0x000055555555a8b7 <+3149>:	mov    -0x294(%rbp),%eax
   0x000055555555a8bd <+3155>:	add    %edx,%eax
   0x000055555555a8bf <+3157>:	movslq %eax,%rdx
   0x000055555555a8c2 <+3160>:	lea    -0x210(%rbp),%rax
   0x000055555555a8c9 <+3167>:	mov    %rdx,%rsi
   0x000055555555a8cc <+3170>:	mov    %rax,%rdi
   0x000055555555a8cf <+3173>:	call   0x55555555dc00 <_ZN5Eigen15DenseCoeffsBaseINS_6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EEELi1EEclEl>
   0x000055555555a8d4 <+3178>:	mov    (%rax),%rdx
   0x000055555555a8d7 <+3181>:	movsd  0x8(%rax),%xmm1
   0x000055555555a8dc <+3186>:	movq   %rdx,%xmm0
   0x000055555555a8e1 <+3191>:	mov    %rbx,%rdi
   0x000055555555a8e4 <+3194>:	call   0x555555558fc6 <_ZN6Bipole10setCurrentESt7complexIdE>

212		}
213	    }
214	}
   0x000055555555a902 <+3224>:	lea    -0x200(%rbp),%rax
   0x000055555555a909 <+3231>:	mov    %rax,%rdi
   0x000055555555a90c <+3234>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555a911 <+3239>:	lea    -0x210(%rbp),%rax
   0x000055555555a918 <+3246>:	mov    %rax,%rdi
   0x000055555555a91b <+3249>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555a920 <+3254>:	lea    -0x220(%rbp),%rax
   0x000055555555a927 <+3261>:	mov    %rax,%rdi
   0x000055555555a92a <+3264>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555a92f <+3269>:	lea    -0x140(%rbp),%rax
   0x000055555555a936 <+3276>:	mov    %rax,%rdi
   0x000055555555a939 <+3279>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555a93e <+3284>:	lea    -0x160(%rbp),%rax
   0x000055555555a945 <+3291>:	mov    %rax,%rdi
   0x000055555555a948 <+3294>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555a94d <+3299>:	lea    -0x180(%rbp),%rax
   0x000055555555a954 <+3306>:	mov    %rax,%rdi
   0x000055555555a957 <+3309>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555a95c <+3314>:	lea    -0x1a0(%rbp),%rax
   0x000055555555a963 <+3321>:	mov    %rax,%rdi
   0x000055555555a966 <+3324>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555a96b <+3329>:	lea    -0x1c0(%rbp),%rax
   0x000055555555a972 <+3336>:	mov    %rax,%rdi
   0x000055555555a975 <+3339>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555a97a <+3344>:	lea    -0x230(%rbp),%rax
   0x000055555555a981 <+3351>:	mov    %rax,%rdi
   0x000055555555a984 <+3354>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555a989 <+3359>:	lea    -0x1e0(%rbp),%rax
   0x000055555555a990 <+3366>:	mov    %rax,%rdi
   0x000055555555a993 <+3369>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555a998 <+3374>:	mov    -0x18(%rbp),%rax
   0x000055555555a99c <+3378>:	sub    %fs:0x28,%rax
   0x000055555555a9a5 <+3387>:	je     0x55555555aada <_ZN7Circuit8KCLSolveEv+3696>
   0x000055555555a9ab <+3393>:	jmp    0x55555555aad5 <_ZN7Circuit8KCLSolveEv+3691>
   0x000055555555a9b0 <+3398>:	endbr64
   0x000055555555a9cc <+3426>:	mov    %rax,%rbx
   0x000055555555a9cf <+3429>:	lea    -0x200(%rbp),%rax
   0x000055555555a9d6 <+3436>:	mov    %rax,%rdi
   0x000055555555a9d9 <+3439>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555a9de <+3444>:	jmp    0x55555555a9e7 <_ZN7Circuit8KCLSolveEv+3453>
   0x000055555555a9e0 <+3446>:	endbr64
   0x000055555555a9e4 <+3450>:	mov    %rax,%rbx
   0x000055555555a9e7 <+3453>:	lea    -0x210(%rbp),%rax
   0x000055555555a9ee <+3460>:	mov    %rax,%rdi
   0x000055555555a9f1 <+3463>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555a9f6 <+3468>:	jmp    0x55555555a9ff <_ZN7Circuit8KCLSolveEv+3477>
   0x000055555555a9f8 <+3470>:	endbr64
   0x000055555555a9fc <+3474>:	mov    %rax,%rbx
   0x000055555555a9ff <+3477>:	lea    -0x220(%rbp),%rax
   0x000055555555aa06 <+3484>:	mov    %rax,%rdi
   0x000055555555aa09 <+3487>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555aa0e <+3492>:	jmp    0x55555555aa17 <_ZN7Circuit8KCLSolveEv+3501>
   0x000055555555aa10 <+3494>:	endbr64
   0x000055555555aa14 <+3498>:	mov    %rax,%rbx
   0x000055555555aa17 <+3501>:	lea    -0x140(%rbp),%rax
   0x000055555555aa1e <+3508>:	mov    %rax,%rdi
   0x000055555555aa21 <+3511>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555aa26 <+3516>:	jmp    0x55555555aa2f <_ZN7Circuit8KCLSolveEv+3525>
   0x000055555555aa28 <+3518>:	endbr64
   0x000055555555aa2c <+3522>:	mov    %rax,%rbx
   0x000055555555aa2f <+3525>:	lea    -0x160(%rbp),%rax
   0x000055555555aa36 <+3532>:	mov    %rax,%rdi
   0x000055555555aa39 <+3535>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555aa3e <+3540>:	jmp    0x55555555aa47 <_ZN7Circuit8KCLSolveEv+3549>
   0x000055555555aa40 <+3542>:	endbr64
   0x000055555555aa44 <+3546>:	mov    %rax,%rbx
   0x000055555555aa47 <+3549>:	lea    -0x180(%rbp),%rax
   0x000055555555aa4e <+3556>:	mov    %rax,%rdi
   0x000055555555aa51 <+3559>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555aa56 <+3564>:	jmp    0x55555555aa5f <_ZN7Circuit8KCLSolveEv+3573>
   0x000055555555aa58 <+3566>:	endbr64
   0x000055555555aa5c <+3570>:	mov    %rax,%rbx
   0x000055555555aa5f <+3573>:	lea    -0x1a0(%rbp),%rax
   0x000055555555aa66 <+3580>:	mov    %rax,%rdi
   0x000055555555aa69 <+3583>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555aa6e <+3588>:	jmp    0x55555555aa77 <_ZN7Circuit8KCLSolveEv+3597>
   0x000055555555aa70 <+3590>:	endbr64
   0x000055555555aa74 <+3594>:	mov    %rax,%rbx
   0x000055555555aa77 <+3597>:	lea    -0x1c0(%rbp),%rax
   0x000055555555aa7e <+3604>:	mov    %rax,%rdi
   0x000055555555aa81 <+3607>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555aa86 <+3612>:	jmp    0x55555555aa8f <_ZN7Circuit8KCLSolveEv+3621>
   0x000055555555aa88 <+3614>:	endbr64
   0x000055555555aa8c <+3618>:	mov    %rax,%rbx
   0x000055555555aa8f <+3621>:	lea    -0x230(%rbp),%rax
   0x000055555555aa96 <+3628>:	mov    %rax,%rdi
   0x000055555555aa99 <+3631>:	call   0x55555555c944 <_ZN5Eigen6MatrixISt7complexIdELin1ELi1ELi0ELin1ELi1EED2Ev>
   0x000055555555aa9e <+3636>:	jmp    0x55555555aaa7 <_ZN7Circuit8KCLSolveEv+3645>
   0x000055555555aaa0 <+3638>:	endbr64
   0x000055555555aaa4 <+3642>:	mov    %rax,%rbx
   0x000055555555aaa7 <+3645>:	lea    -0x1e0(%rbp),%rax
   0x000055555555aaae <+3652>:	mov    %rax,%rdi
   0x000055555555aab1 <+3655>:	call   0x55555555c904 <_ZN5Eigen6MatrixISt7complexIdELin1ELin1ELi0ELin1ELin1EED2Ev>
   0x000055555555aab6 <+3660>:	mov    %rbx,%rax
   0x000055555555aab9 <+3663>:	mov    -0x18(%rbp),%rdx
   0x000055555555aabd <+3667>:	sub    %fs:0x28,%rdx
   0x000055555555aac6 <+3676>:	je     0x55555555aacd <_ZN7Circuit8KCLSolveEv+3683>
   0x000055555555aac8 <+3678>:	call   0x555555556310 <__stack_chk_fail@plt>
   0x000055555555aacd <+3683>:	mov    %rax,%rdi
   0x000055555555aad0 <+3686>:	call   0x5555555563a0 <_Unwind_Resume@plt>
   0x000055555555aad5 <+3691>:	call   0x555555556310 <__stack_chk_fail@plt>
   0x000055555555aada <+3696>:	mov    -0x8(%rbp),%rbx
   0x000055555555aade <+3700>:	leave
   0x000055555555aadf <+3701>:	ret

End of assembler dump.
Warning: 'set logging off', an alias for the command 'set logging enabled', is deprecated.
Use 'set logging enabled off'.

