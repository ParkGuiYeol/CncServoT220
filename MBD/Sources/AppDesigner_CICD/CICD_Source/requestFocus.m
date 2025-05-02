function requestFocus(app)
    jTextArea = findjobj(app.S01_TA_Build);
    if ~isempty(jTextArea)
        jTextArea.requestFocus();
    end
end