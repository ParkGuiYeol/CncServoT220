function progressbar(varargin)
% PROGRESSBAR - Simple graphical progress bar (always on top)
%
% Usage:
%   progressbar('Title')                 - Initializes the bar
%   progressbar(Fraction)                - Updates progress
%   progressbar()                        - Closes the progress bar

persistent progFig progAxes progPatch progText numBars

% Close if no input
if nargin == 0 && ~isempty(progFig)
    if ishandle(progFig)
        close(progFig);
    end
    clear progFig progAxes progPatch progText numBars
    return;
end

% Initialize with titles
if nargin > 0 && ischar(varargin{1})
    % Close previous if open
    if ~isempty(progFig) && ishandle(progFig)
        close(progFig);
    end

    numBars = nargin;
    screenSize = get(0,'ScreenSize');
    figWidth = 360;
    figHeight = 75 + 30*(numBars - 1);

    progFig = figure( ...
        'Name','Progress', ...
        'NumberTitle','off', ...
        'MenuBar','none', ...
        'ToolBar','none', ...
        'Resize','off', ...
        'WindowStyle','normal', ...
        'Visible','off', ...
        'Position', [ ...
            screenSize(3)/2 - figWidth/2, ...
            screenSize(4)/2 - figHeight/2, ...
            figWidth, figHeight]);

    % Always bring forward
    drawnow;
    figure(progFig);

    % 👉 Java hack: Set Always on Top
    % try
    %     jFrame = get(handle(progFig), 'JavaFrame');
    %     try
    %         jWindow = jFrame.fHG2Client.getWindow();  % R2014b+
    %     catch
    %         jWindow = jFrame.fFigureClient.getWindow();  % Fallback
    %     end
    %     jWindow.setAlwaysOnTop(true);  % ✅ 핵심 설정
    % catch
    %     warning('JavaFrame not supported. "Always on top" might not work.');
    % end

    warning off all   % 모든 경고 숨김
    % JavaFrame 사용 코드
    jFrame = get(handle(progFig), 'JavaFrame');
    jWindow = jFrame.fHG2Client.getWindow();
    jWindow.setAlwaysOnTop(true);
    warning on all    % 다시 경고 켜기

    progAxes = gobjects(numBars,1);
    progPatch = gobjects(numBars,1);
    progText = gobjects(numBars,1);

    for bar = 1:numBars
        bottom = (numBars - bar) * 30 + 20;

        progAxes(bar) = axes( ...
            'Parent', progFig, ...
            'Units','pixels', ...
            'Position',[20 bottom 320 20], ...
            'Box','on', ...
            'XLim',[0 1], ...
            'YLim',[0 1], ...
            'XTick',[], ...
            'YTick',[] );

        progPatch(bar) = patch( ...
            'Parent', progAxes(bar), ...
            'XData',[0 0 0 0], ...
            'YData',[0 0 1 1], ...
            'FaceColor',[0 0.7 0.2] );

        progText(bar) = uicontrol( ...
            'Style','text', ...
            'Parent', progFig, ...
            'Units','pixels', ...
            'Position',[20 bottom + 22 320 15], ...
            'String',varargin{bar}, ...
            'HorizontalAlignment','left' );
    end

    set(progFig,'Visible','on');
    drawnow;
    return;
end

% Update progress
if isnumeric(varargin{1})
    if isempty(progFig) || ~ishghandle(progFig)
        error('PROGRESSBAR: You must initialize progressbar with title(s) first.');
    end

    for bar = 1:length(varargin)
        fraction = min(max(varargin{bar}, 0), 1);  % Clamp [0,1]
        set(progPatch(bar), 'XData', [0 fraction fraction 0]);

        % 👉 퍼센트 텍스트 업데이트
        percentStr = sprintf('%.0f%%', fraction * 100);
        baseTitle = inputname(bar);
        if isempty(baseTitle) || strcmp(baseTitle, 'varargin')
            baseTitle = '';  % fallback
        end
        set(progText(bar), 'String', [baseTitle ' ' percentStr]);
    end
    drawnow;
end