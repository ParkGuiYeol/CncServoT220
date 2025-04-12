classdef CtrlMde < uint16  % uint16를 상속하여 숫자값 사용 가능
    enumeration
        VF(1)
        Vctrl(2)
        Crt(4)
        Tq(8)
        Spd(16)
        Pst(32)
        VAlign(64)
        IAlign(128)
        IF(256)
    end
end